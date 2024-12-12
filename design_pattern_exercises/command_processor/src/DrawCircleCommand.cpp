#include "DrawCircleCommand.h"

namespace DrawCircleCommand
{
    void DrawCircleCommand::execute()
    {
        reciever.drawCircle(centerPoint, radius);
    }
    
    void DrawCircleCommand::undo()
    {
        reciever.eraseCricle(centerPoint, radius);
    }
}