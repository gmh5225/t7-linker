#pragma once

#include <MinHook.h>

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#define HOOK_JUMP true
#define HOOK_CALL false

namespace Utils
{
	class Hook
	{
	public:
		class Signature
		{
		public:
			class Container
			{
			public:
				const char* signature;
				std::string mask;
				std::function<void(unsigned char*)> callback;
			};

			Signature(void* _start, size_t _length) : start(_start), length(_length) {}
			Signature(size_t _start, size_t _length) : Signature(reinterpret_cast<void*>(_start), _length) {}
			Signature() : Signature(0x400000, 0x800000) {}

			void process();
			void add(Container container);

		private:
			void* start;
			size_t length;
			std::vector<Container> signatures;
		};

		class Interceptor
		{
		public:
			static void Install(void* place, void* stub);
			static void Install(void* place, void(*stub)());
			static void Install(void** place, void(*stub)());

		private:
			static std::map<void*, void*> IReturn;
			static std::map<void*, void(*)()> ICallbacks;

			static void InterceptionStub();
			static void RunCallback(void* place);
			static void* PopReturn(void* place);
		};

		class IAT
		{
		public:
			static bool Replace(Utils::NT::Module module, std::string targetModule, std::string process, void* stub);
		};

		class Detour
		{
		public:
			Detour(bool keep = false);
			~Detour();

            template <typename T> static T* Static_C(const std::uintptr_t& address, const T& dest)
            {
                Detour hook(true);
                hook.create(LPVOID(address), LPVOID(dest));

                return reinterpret_cast<T*>(hook.get<T*>());
            }
			template <typename T> static std::function<T> Static(const std::uintptr_t& address, const T& dest)
			{
				Detour hook(true);
				hook.create(LPVOID(address), LPVOID(dest));

				return std::function<T>(reinterpret_cast<T*>(hook.get<T*>()));
			}

			void create(void* target, void* function);
			void remove();

			void enable();
			void disable();

			template<typename T>
			T get()
			{
				return reinterpret_cast<T>(this->original);
			}

			template<typename T, typename... Args>
			T invoke(Args... args)
			{
				return reinterpret_cast<T(__cdecl*)(Args...)>(this->original)(args...);
			}

			template<typename T, typename... Args>
			T invokePascal(Args... args)
			{
				return reinterpret_cast<T(__stdcall*)(Args...)>(this->original)(args...);
			}

			template<typename T, typename... Args>
			T invokeThis(void* thisPtr, Args... args)
			{
				return reinterpret_cast<T(__thiscall*)(Args...)>(this->original)(thisPtr, args...);
			}

		private:
			bool keep;
			void* target;
			void* original;

			class Initializer
			{
			public:
				Initializer();
				~Initializer();
			};
		};

		Hook() : initialized(false), installed(false), place(nullptr), stub(nullptr), original(nullptr), useJump(false), protection(0) { ZeroMemory(this->buffer, sizeof(this->buffer)); }

		Hook(void* place, void* stub, bool useJump = true) : Hook() { this->initialize(place, stub, useJump); }
		Hook(void* place, void(*stub)(), bool useJump = true) : Hook(place, reinterpret_cast<void*>(stub), useJump) {}

		Hook(size_t place, void* stub, bool useJump = true) : Hook(reinterpret_cast<void*>(place), stub, useJump) {}
		Hook(size_t place, size_t stub, bool useJump = true) : Hook(reinterpret_cast<void*>(place), reinterpret_cast<void*>(stub), useJump) {}
		Hook(size_t place, void(*stub)(), bool useJump = true) : Hook(reinterpret_cast<void*>(place), reinterpret_cast<void*>(stub), useJump) {}

		~Hook();

		Hook* initialize(void* place, void* stub, bool useJump = true);
		Hook* initialize(size_t place, void* stub, bool useJump = true);
		Hook* initialize(size_t place, void(*stub)(...), bool useJump = true); // For lambdas
		Hook* install(bool unprotect = true, bool keepUnprotected = false);
		Hook* uninstall(bool unprotect = true);

		void* getAddress();
		void quick();

		template <typename T> static std::function<T> Call(size_t function)
		{
			return std::function<T>(reinterpret_cast<T*>(function));
		}

		template <typename T> static std::function<T> Call(FARPROC function)
		{
			return Hook::Call<T>(reinterpret_cast<size_t>(function));
		}

		template <typename T> static std::function<T> Call(void* function)
		{
			return Hook::Call<T>(reinterpret_cast<size_t>(function));
		}

		static void SetString(void* place, const char* string, size_t length);
		static void SetString(size_t place, const char* string, size_t length);

		static void SetString(void* place, const char* string);
		static void SetString(size_t place, const char* string);

		static void Nop(void* place, size_t length);
		static void Nop(size_t place, size_t length);

		static void RedirectJump(void* place, void* stub);
		static void RedirectJump(size_t place, void* stub);

		template <typename T> static void Set(void* place, T value)
		{
			DWORD oldProtect;
			VirtualProtect(place, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);

			*static_cast<T*>(place) = value;

			VirtualProtect(place, sizeof(T), oldProtect, &oldProtect);
			FlushInstructionCache(GetCurrentProcess(), place, sizeof(T));
		}

		template <typename T> static void Set(size_t place, T value)
		{
			return Hook::Set<T>(reinterpret_cast<void*>(place), value);
		}

		template <typename T> static void Xor(void* place, T value)
		{
			DWORD oldProtect;
			VirtualProtect(place, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);

			*static_cast<T*>(place) ^= value;

			VirtualProtect(place, sizeof(T), oldProtect, &oldProtect);
			FlushInstructionCache(GetCurrentProcess(), place, sizeof(T));
		}

		template <typename T> static void Xor(size_t place, T value)
		{
			return Hook::Xor<T>(reinterpret_cast<void*>(place), value);
		}

		template <typename T> static void Or(void* place, T value)
		{
			DWORD oldProtect;
			VirtualProtect(place, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);

			*static_cast<T*>(place) |= value;

			VirtualProtect(place, sizeof(T), oldProtect, &oldProtect);
			FlushInstructionCache(GetCurrentProcess(), place, sizeof(T));
		}

		template <typename T> static void Or(size_t place, T value)
		{
			return Hook::Or<T>(reinterpret_cast<void*>(place), value);
		}

		template <typename T> static void And(void* place, T value)
		{
			DWORD oldProtect;
			VirtualProtect(place, sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect);

			*static_cast<T*>(place) &= value;

			VirtualProtect(place, sizeof(T), oldProtect, &oldProtect);
			FlushInstructionCache(GetCurrentProcess(), place, sizeof(T));
		}

		template <typename T> static void And(size_t place, T value)
		{
			return Hook::And<T>(reinterpret_cast<void*>(place), value);
		}

		template <typename T> static T Get(void* place)
		{
			return *static_cast<T*>(place);
		}

		template <typename T> static T Get(size_t place)
		{
			return Hook::Get<T>(reinterpret_cast<void*>(place));
		}

	private:
		bool initialized;
		bool installed;

		void* place;
		void* stub;
		void* original;
		char buffer[5];
		bool useJump;

		DWORD protection;

		std::mutex stateMutex;
	};
}
