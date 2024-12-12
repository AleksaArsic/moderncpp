#include "StdOutLogger.h"

namespace StdOutLogger
{
	void StdOutLogger::stdOutLogInfo(unsigned int componentId,  std::string_view logInformation) const
	{
		std::cout << "[ID]: " << componentId << " [INFO]: " << logInformation << std::endl;
	}

	void StdOutLogger::stdOutLogWarning(unsigned int componentId,  std::string_view logWarning) const 
	{
		std::cout << "[ID]: " << componentId << " [WARNING]: " << logWarning << std::endl;
	}

	void StdOutLogger::stdOutLogError(unsigned int componentId, std::string_view logError) const
	{
		std::cout << "[ID]: " << componentId << " [ERROR]: " << logError << std::endl;
	}
}