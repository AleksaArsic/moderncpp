#pragma once
#include <string>
#include "Formatter.h"
#include "CustomerId.h"
#include "Address.h"

namespace Customer
{
    class Customer
    {
        public:
            // ... Other non-implemented functionality 

            Customer() = delete; 

            Customer(CustomerId::CustomerId& customerId, std::string_view forename, std::string_view surename,
                        Address::Address& address) : customerId(customerId), forename(forename), surename(surename),
                        address(address)
            { }

            std::string getAsFormattedString(Formatter::Formatter& formatter) const;

            // ... Other non-implemented functionality
        private:
            CustomerId::CustomerId customerId;
            std::string forename;
            std::string surename;
            Address::Address address;
    };
}