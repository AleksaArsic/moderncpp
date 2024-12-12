#include "LoggerSingleton.h"
#include "CustomerRepository.h"
#include "LoggingFacility.h"
#include "StdOutLogger.h"

int main()
{
    LoggerSingleton::LoggerSingleton& logger = LoggerSingleton::LoggerSingleton::getLogger();
    logger.stdOutLogError("Hello from LoggerSingleton.");

    std::shared_ptr<LoggingFacility::LoggingFacility> stdOutputLogger = std::make_shared<StdOutLogger::StdOutLogger>();

    // Dependecy injection
    CustomerRepository::CustomerRepository customers{ stdOutputLogger };

    Customer::Customer neededCustomer = customers.findCustomerById(0);

    return 0;
}