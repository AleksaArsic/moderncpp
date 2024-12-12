#include "CustomerRepository.h"
//#include "LoggerSingleton.h"

namespace CustomerRepository
{
	[[nodiscard]] Customer::Customer& CustomerRepository::findCustomerById(const int id) const
	{
		// Bad practice because CustomerRepository class is now "secretly" dependent on LoggerSingleton
		// CustomerRepository class is a good candidate for having dependency injection principle 
		// for injecting the LoggerSingleton class
        // LoggerSingleton::LoggerSingleton.getLogger().stdOutLogInfo("Start searching customer by a specific identifier.");
		logger->stdOutLogInfo("Start searching customer by a specific identifier.");

		// ... additional non-implemented functionality

		return *(customerRepositoryEntries.at(0)); // demonstrational purpose only
	}
}