#include "CustomerId.h"

namespace CustomerId
{
    void CustomerId::setId(std::string_view customerId)
    {
        id = customerId;
    }

    [[nodiscard]] std::string CustomerId::getId() const
    {
        return id;
    }   
}