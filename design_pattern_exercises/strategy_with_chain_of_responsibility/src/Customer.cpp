#include "Customer.h"

namespace Customer
{
    std::string Customer::getAsFormattedString(Formatter::Formatter& formatter) const
    {
        return formatter.withCustomerId(customerId.getId()).
                           withForename(forename).
                           withSurename(surename).
                             withStreet(address.getStreet()).
                            withZipCode(address.getZipCodeAsString()).
                               withCity(address.getCity()).
                                 format();
    }
}