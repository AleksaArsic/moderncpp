#pragma once 
#include <string_view>

namespace LoggingFacility
{
	class LoggingFacility
	{
		public:
			virtual ~LoggingFacility() = default;
			virtual void stdOutLogInfo(std::string_view logInformation) = 0;
			virtual void stdOutLogWarning(std::string_view logWarning) = 0;
			virtual void stdOutLogError(std::string_view logError) = 0;
	};
}