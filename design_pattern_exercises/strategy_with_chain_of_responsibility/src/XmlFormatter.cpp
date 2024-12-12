#include "XmlFormatter.h"
#include <sstream>

namespace XmlFormatter
{
    std::string XmlFormatter::format() const
    {
        std::stringstream formattedString { };

        formattedString << "<customer id=\"" << customerId << "\">\n" 
                        << "    <forename>" << forename << "</forename>\n" 
                        << "    <surename>" << surename << "</surename>\n"
                        << "    <street>" << street << "</street>\n" 
                        << "    <zipcode>" << zipCode << "</zipcode>\n"
                        << "    <city>" << city << "</city>" 
                        << "\n</customer>\n";

        return formattedString.str();        
    }    
}