#pragma once
#include <string_view>
#include <iostream>
#include "LoggingFacility.h"

namespace StdOutLogger
{
	class StdOutLogger final
	{
		public:
			StdOutLogger() = default;
			void stdOutLogInfo(unsigned int componentId, std::string_view logInformation) const;
			void stdOutLogWarning(unsigned int componentId, std::string_view logWarning) const;
			void stdOutLogError(unsigned int componentId, std::string_view logError) const;

	};
}