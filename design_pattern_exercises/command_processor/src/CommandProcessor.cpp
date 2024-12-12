#include "CommandProcessor.h"

namespace CommandProcessor
{
    void CommandProcessor::execute(const std::shared_ptr<Command::UndoableCommand>& commandPtr)
    {
        commandPtr->execute();
        commandHistory.push(commandPtr);
    }

    void CommandProcessor::undoLastCommand()
    {
        if(commandHistory.empty())
        {
            return;
        }

        commandHistory.top()->undo();
        commandHistory.pop();
    }
}