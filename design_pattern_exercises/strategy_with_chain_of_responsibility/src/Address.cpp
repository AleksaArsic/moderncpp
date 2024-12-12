#include "Address.h"

namespace Address
{
    void Address::setStreet(std::string_view streetName)
    {
        street = streetName;
    }

    void Address::setZipCode(std::string_view zipCodeValue)
    {
        zipCode = zipCodeValue;
    }

    void Address::setCityName(std::string_view cityName)
    {
        city = cityName;
    }

    std::string Address::getStreet() const
    {
        return street;
    }

    std::string Address::getZipCodeAsString() const
    {
        return zipCode;
    }

    std::string Address::getCity() const
    {
        return city;
    }
}