#include "LoggerSingleton.h"
#include "CustomerRepository.h"
#include "LoggingFacility.h"
#include "StdOutLogger.h"
#include "LoggerFactory.h"

int main()
{
    // Using LoggerSingleton
    //LoggerSingleton::LoggerSingleton& logger = LoggerSingleton::LoggerSingleton::getLogger();
    //logger.stdOutLogError("Hello from LoggerSingleton.");

    //std::shared_ptr<LoggingFacility::LoggingFacility> stdOutputLogger = std::make_shared<StdOutLogger::StdOutLogger>();

    // Using LoggerFactory
    LoggerFactory::LoggerFactory loggerFactory("This is a filepath to the configuration file");
    std::shared_ptr<LoggingFacility::LoggingFacility> loggingFacilityPtr = loggerFactory.create();

    // Dependecy injection
    CustomerRepository::CustomerRepository customers{ loggingFacilityPtr };

    Customer::Customer neededCustomer = customers.findCustomerById(0);

    return 0;
}