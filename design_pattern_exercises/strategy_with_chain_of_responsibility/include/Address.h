#pragma once
#include <string>

namespace Address
{
    class Address
    {
        public:
            Address() = delete;

            Address(std::string_view streetName, std::string_view zipCodeValue, std::string_view cityName) :
                street(streetName), zipCode(zipCodeValue), city(cityName)
                { }

            void setStreet(std::string_view streetName);
            void setZipCode(std::string_view zipCodeValue);
            void setCityName(std::string_view cityName);

            std::string getStreet() const;
            std::string getZipCodeAsString() const;
            std::string getCity() const;

        private:
            std::string street     { "n/a" };
            std::string zipCode    { "n/a" };
            std::string city       { "n/a" };            
    };
}