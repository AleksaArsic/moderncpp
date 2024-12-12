#include "StdOutLogger.h"

namespace StdOutLogger
{
	void StdOutLogger::stdOutLogInfo(std::string_view logInformation)
	{
		std::cout << "[INFO]: " << logInformation << std::endl;
	}

	void StdOutLogger::stdOutLogWarning(std::string_view logWarning)
	{
		std::cout << "[WARNING]: " << logWarning << std::endl;
	}

	void StdOutLogger::stdOutLogError(std::string_view logError)
	{
		std::cout << "[ERROR]: " << logError << std::endl;
	}
}