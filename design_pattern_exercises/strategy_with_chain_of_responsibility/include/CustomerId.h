#pragma once
#include <string>

namespace CustomerId
{
    class CustomerId
    {
        public:
            CustomerId() = default;

            CustomerId(std::string_view customerId) : id(customerId)
            { }

            void setId(std::string_view customerId);
            [[nodiscard]] std::string getId() const;
        private:
            std::string id { "00000" };
    };
}