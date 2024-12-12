#include "Command.h"
#include "CommandProcessor.h"

namespace UndoCommand
{
    class UndoCommand : public Command::UndoableCommand
    {
        public:
            explicit UndoCommand(CommandProcessor::CommandProcessor& receiver) :
                receiver { receiver }
            { }

            virtual void execute() override;
            virtual void undo() override;

        private:
            CommandProcessor::CommandProcessor& receiver;
    };
}