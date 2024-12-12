#include "CustomerRepository.h"
#include "LoggingFacility.h"
#include "StdOutLogger.h"
#include "StdOutLoggerAdapter.h"

int main()
{
    // Create StdOutLogger
    StdOutLogger::StdOutLogger stdOutLogger;

    stdOutLogger.stdOutLogInfo(1U, "Hello from Logger.");

    // Create StdOutLoggerAdapter
    StdOutLoggerAdapter::StdOutLoggerAdapter stdOutLoggerAdapter;
    stdOutLoggerAdapter.setComponentId(2U);
    stdOutLoggerAdapter.stdOutLogInfo("Hello from Logger Adapter.");

    std::shared_ptr<LoggingFacility::LoggingFacility> stdOutputLogger = std::make_shared<StdOutLoggerAdapter::StdOutLoggerAdapter>();

    // Dependecy injection
    CustomerRepository::CustomerRepository customers{ stdOutputLogger };

    Customer::Customer neededCustomer = customers.findCustomerById(0);

    return 0;
}