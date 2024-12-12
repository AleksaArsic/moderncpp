#include <iostream>
#include "PlainTextFormatter.h"
#include "XmlFormatter.h"
#include "JsonFormatter.h"
#include "Customer.h"
#include "CustomerId.h"
#include "Address.h"

int main()
{
    CustomerId::CustomerId customerId { "03033" };
    Address::Address address { "Nikole Tesle 33", "32010", "Vukovar" };
    Customer::Customer customer {customerId, "Aleksa", "Arsic", address};

    PlainTextFormatter::PlainTextFormatter plainTextFormatter;
    XmlFormatter::XmlFormatter xmlFormatter;
    JsonFormatter::JsonFormatter jsonFormatter;

    std::cout << "Plain text: \n" << customer.getAsFormattedString(plainTextFormatter) << std::endl;
    std::cout << "Xml text: \n" << customer.getAsFormattedString(xmlFormatter) << std::endl;
    std::cout << "JSON text: \n" << customer.getAsFormattedString(jsonFormatter) << std::endl;

    return 0;
}