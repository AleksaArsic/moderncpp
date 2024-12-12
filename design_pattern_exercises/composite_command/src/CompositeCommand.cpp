#include "CompositeCommand.h"
#include <ranges>

namespace CompositeCommand
{
    void CompositeCommand::addCommand(const std::shared_ptr<UndoableCommand>& command)
    {
        commands.push_back(command);
    }

    void CompositeCommand::execute()
    {
        for (const auto& command : commands)
        {
            command->execute();
        }
    }

    void CompositeCommand::undo()
    {
        const auto& commandsInReverseOrder = std::ranges::reverse_view(commands);

        for (const auto& command : commandsInReverseOrder)
        {
            command->undo();
        }
    }
}