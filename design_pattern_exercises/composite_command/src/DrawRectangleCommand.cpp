#include "DrawRectangleCommand.h"

namespace DrawRectangleCommand
{
    void DrawRectangleCommand::execute()
    {
        reciever.drawRectangle(topLeftPoint, dimensions.width, dimensions.height);
    }

    void DrawRectangleCommand::undo()
    {
        reciever.eraseRectangle(topLeftPoint, dimensions.width, dimensions.height);
    }
}