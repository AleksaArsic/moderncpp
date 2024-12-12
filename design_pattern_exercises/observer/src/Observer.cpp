#include "Observer.h"

namespace Observer
{
    bool operator==(const Observer& lhs, const Observer& rhs)
    {
        return lhs.getId() == rhs.getId();
    }    
}