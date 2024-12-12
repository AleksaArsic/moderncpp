#include "UndoCommand.h"

namespace UndoCommand
{
    void UndoCommand::execute()
    {
        receiver.undoLastCommand();
    }

    void UndoCommand::undo()
    {
        // Intenionally left blank, because an undo should not be undone
    }
}