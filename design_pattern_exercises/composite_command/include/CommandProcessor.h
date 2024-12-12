#pragma once
#include <stack>
#include <memory>
#include "Command.h"

namespace CommandProcessor
{
    class CommandProcessor
    {
        public:
            void execute(const std::shared_ptr<Command::UndoableCommand>& commandPtr);
            void undoLastCommand();
        private:
            std::stack<std::shared_ptr<Command::Revertable>> commandHistory;
    };
}