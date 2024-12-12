#include "PlainTextFormatter.h"
#include <sstream>

namespace PlainTextFormatter
{
    std::string PlainTextFormatter::format() const
    {
        std::stringstream formattedString { };

        formattedString << "[" << customerId << "]: " 
                        << forename << " " << surename << ", "
                        << street << ", " << zipCode << " "
                        << city << ".";

        return formattedString.str();
    }    
}