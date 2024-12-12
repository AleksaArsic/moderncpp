#include "Formatter.h"

namespace Formatter
{
    Formatter& Formatter::withCustomerId(std::string_view customerId)
    {
        this->customerId = customerId;
        return *this;
    }

    Formatter& Formatter::withForename(std::string_view forename)
    {
        this->forename = forename;
        return *this;
    }

    Formatter& Formatter::withSurename(std::string_view surename)
    {
        this->surename = surename;
        return *this;
    }
    
    Formatter& Formatter::withStreet(std::string_view street)    
    {
        this->street = street;
        return *this;
    }

    Formatter& Formatter::withZipCode(std::string_view zipCode)
    {
        this->zipCode = zipCode;
        return *this;
    }
    
    Formatter& Formatter::withCity(std::string_view city)
    {
        this->city = city;
        return *this;
    }
}