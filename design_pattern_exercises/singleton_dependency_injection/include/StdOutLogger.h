#pragma once
#include <memory>
#include <string_view>
#include <iostream>
#include "LoggingFacility.h"

namespace StdOutLogger
{
	class StdOutLogger : public LoggingFacility::LoggingFacility
	{
		public:
			virtual void stdOutLogInfo(std::string_view logInformation) override final;
			virtual void stdOutLogWarning(std::string_view logWarning) override final;
			virtual void stdOutLogError(std::string_view logError) override final;

	};
}