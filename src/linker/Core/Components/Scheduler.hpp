#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

#include "Core/Component.hpp"

namespace Components
{
	class Scheduler : public IComponent
	{
	public:
		Scheduler();
		~Scheduler();

		static void Once(Utils::Slot<void()> slot);
		static void OnFrame(Utils::Slot<void()> slot);
		static void OnDelay(Utils::Slot<void()> callback, std::chrono::nanoseconds delay, bool deleteOnExecute = false);

	private:
		class DelayedSlot
		{
		public:
			std::chrono::nanoseconds delay;
			Utils::Time::Interval interval;
			Utils::Slot<void()> callback;
			bool deleteSlot;
		};

		static std::mutex Mutex;
		static Utils::Signal<void()> OnceSignal;
		static Utils::Signal<void()> FrameSignal;
		static std::vector<DelayedSlot> DelayedSlots;

		static void DelaySignal();

		static void Frame();
	};
}
