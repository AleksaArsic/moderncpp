#pragma once
#include <vector>
#include <memory>
#include "Customer.h"
#include "LoggingFacility.h"

namespace CustomerRepository
{
	using Logger = std::shared_ptr<LoggingFacility::LoggingFacility>;

	class CustomerRepository
	{
		public:
			// ... additional non-implemented functionality

			CustomerRepository() = delete;

			explicit CustomerRepository(const Logger& newLogger) : logger { newLogger }
			{
				// push first dummy entry
				customerRepositoryEntries.push_back(std::make_shared<Customer::Customer>());
			}

			[[nodiscard]] Customer::Customer& findCustomerById(const int id) const;

			// ... additional non-implemented funcitonality 
		private:
			Logger logger;

			std::vector<std::shared_ptr<Customer::Customer>> customerRepositoryEntries;
	};
}