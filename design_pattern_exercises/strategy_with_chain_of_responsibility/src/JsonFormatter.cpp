#include "JsonFormatter.h"
#include <sstream>

namespace JsonFormatter
{
    std::string JsonFormatter::format() const
    {
        std::stringstream formattedString { };

        formattedString << "{\n"
                        << "CustomerId: \"" << customerId << END_OF_PROPERTY
                        << "\"Forename: \"" << forename << END_OF_PROPERTY
                        << "\"Surename: \"" << surename << END_OF_PROPERTY
                        << "\"Street: \"" << street << END_OF_PROPERTY
                        << "\"ZIP Code: \"" << zipCode << END_OF_PROPERTY
                        << "\"City: \"" << city << "\"\n"
                        << "}\n";

        return formattedString.str();  
    }
}