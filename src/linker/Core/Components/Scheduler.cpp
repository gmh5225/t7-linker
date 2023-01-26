#include "STDInclude.hpp"

#include "Game/Game.hpp"
#include "Core/Components/Scheduler.hpp"

namespace Components
{
	std::mutex Scheduler::Mutex;
	Utils::Signal<void()> Scheduler::OnceSignal;
	Utils::Signal<void()> Scheduler::FrameSignal;
	std::vector<Scheduler::DelayedSlot> Scheduler::DelayedSlots;

	void Scheduler::Once(Utils::Slot<void()> slot)
	{
		Scheduler::OnceSignal.connect(slot);
	}

	void Scheduler::OnFrame(Utils::Slot<void()> slot)
	{
		Scheduler::FrameSignal.connect(slot);
	}

	void Scheduler::OnDelay(Utils::Slot<void()> callback, std::chrono::nanoseconds delay, bool deleteOnExecute /*= false*/)
	{
		std::lock_guard<std::mutex> _(Scheduler::Mutex);

		Scheduler::DelayedSlot slot;
		slot.callback = callback;
		slot.delay = delay;
		slot.deleteSlot = deleteOnExecute;

		Scheduler::DelayedSlots.push_back(slot);
	}

	void Scheduler::Frame()
	{
		Scheduler::DelaySignal();
		Scheduler::FrameSignal();

		Utils::Signal<void()> copy(Scheduler::OnceSignal);
		Scheduler::OnceSignal.clear();
		copy();
	}

	void Scheduler::DelaySignal()
	{
		Utils::Signal<void()> signal;
		{
			std::lock_guard<std::mutex> _(Scheduler::Mutex);
			for (auto i = Scheduler::DelayedSlots.begin(); i != Scheduler::DelayedSlots.end();)
			{
				if (i->interval.elapsed(i->delay))
				{
					signal.connect(i->callback);
					i->interval.update();

					if (i->deleteSlot) i = Scheduler::DelayedSlots.erase(i);
					else ++i;

					continue;
				}

				++i;
			}
		}

		signal();
	}

	Scheduler::Scheduler()
	{
		Utils::Hook(0x693E10, Scheduler::Frame, HOOK_CALL).install()->quick();
	}

	Scheduler::~Scheduler()
	{
		Scheduler::OnceSignal.clear();
		Scheduler::FrameSignal.clear();
	}
}
