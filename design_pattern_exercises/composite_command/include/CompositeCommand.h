#pragma once
#include "Command.h"
#include <memory>
#include <vector>

namespace CompositeCommand
{
    class CompositeCommand : public Command::UndoableCommand
    {
        public:
            void addCommand(const std::shared_ptr<UndoableCommand>& command);
            virtual void execute() override;
            virtual void undo() override;
        private:
            std::vector<std::shared_ptr<UndoableCommand>> commands;
    };
}