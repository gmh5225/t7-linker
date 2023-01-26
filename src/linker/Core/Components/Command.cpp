#include "STDInclude.hpp"

#include "Game/Game.hpp"
#include "Core/Components/Command.hpp"
#include "Core/Components/Console.hpp"

namespace Components
{
	std::map<std::string, Utils::Slot<void(Command::Params)>> Command::Handlers;

	Command::Params::Params() {}

	const char* Command::Params::get(size_t index)
	{
		if (index >= this->size()) return "";

		return Game::Cmd_Argv(index);
	}

	size_t Command::Params::size()
	{
		return Game::Cmd_Argc();
	}

	std::string Command::Params::join(size_t startIndex)
	{
		std::string result;

		for (size_t i = startIndex; i < this->size(); ++i)
		{
			if (i > startIndex) result.append(" ");
			result.append(this->get(i));
		}

		return result;
	}

	void Command::Callback()
	{
		Command::Params params;

		auto handler = Command::Handlers.find(Utils::String(params.get(0)).toLower());
		if (handler != Command::Handlers.end())
		{
			handler->second(params);
		}
	}

	void Command::Execute(std::string command, bool sync)
	{
		if (sync)
		{
			return Game::Cmd_ExecuteSingleCommand(Game::ONLY_LOCAL_CLIENT, Game::CONTROLLER_INDEX_FIRST, command.data(), false);
		}
		else
		{
			return Game::Cbuf_AddText(Game::ONLY_LOCAL_CLIENT, command.data());
		}
	}

	void Command::Add(Utils::String command, Utils::Slot<void(Command::Params)> handler)
	{
		Command::Handlers[command.toLower()] = handler;

		Game::cmd_function_s* newCmd = Utils::Memory::GetAllocator()->allocate<Game::cmd_function_s>();
		newCmd->name = Utils::Memory::GetAllocator()->duplicateString(command);
		newCmd->function = Command::Callback;
		newCmd->next = Game::cmd_functions;
		Game::cmd_functions = newCmd;
	}

	Command::Command()
	{
		// Add the quit command
		Game::cmd_function_s* comQuitVar = reinterpret_cast<Game::cmd_function_s*>(0x1E4B034);
		comQuitVar->name = "quit";
		comQuitVar->function = (void(*)())0x6C5F30;
		comQuitVar->next = Game::cmd_functions;
		Game::cmd_functions = comQuitVar;
	}

	Command::~Command()
	{
		Command::Handlers.clear();
	}
}
