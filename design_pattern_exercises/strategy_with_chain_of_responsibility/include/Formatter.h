#pragma once
#include <memory>
#include <string>
#include <string_view>

// Formatter implements Chain of responsibility design pattern

namespace Formatter
{
    class Formatter
    {
        public:
            virtual ~Formatter() = default;

            Formatter& withCustomerId(std::string_view customerId);
            Formatter& withForename(std::string_view customerId);
            Formatter& withSurename(std::string_view customerId);
            Formatter& withStreet(std::string_view customerId);
            Formatter& withZipCode(std::string_view customerId);
            Formatter& withCity(std::string_view customerId);
            
            virtual std::string format() const = 0;

        protected:
            std::string customerId { "00000" };
            std::string forename   { "n/a"   };
            std::string surename   { "n/a"   };
            std::string street     { "n/a"   };
            std::string zipCode    { "n/a"   };
            std::string city       { "n/a"   };
    };
}