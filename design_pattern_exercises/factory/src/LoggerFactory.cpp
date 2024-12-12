#include "LoggerFactory.h"
#include "StdOutLogger.h"

namespace LoggerFactory
{
    std::shared_ptr<LoggingFacility::LoggingFacility> LoggerFactory::create() const
    {
        const std::string configurationFileContent = readConfigurationFile(configurationFileName);
        OutputTarget outputTarget = evaluateConfiguration(configurationFileContent);
        return createLogger(outputTarget);
    }

    std::string LoggerFactory::readConfigurationFile(std::string configurationFileName) const
    {
		// ... additional non-implemented functionality

        return "configuration file name";
    }

    LoggerFactory::OutputTarget LoggerFactory::evaluateConfiguration(std::string configurationFileContent) const
    {
		// ... additional non-implemented functionality

        return OutputTarget::STDOUT;
    }

    std::shared_ptr<LoggingFacility::LoggingFacility> LoggerFactory::createLogger(LoggerFactory::OutputTarget outputTarget) const
    {
		switch(outputTarget)
        {
            case OutputTarget::FILE:
		        // ... additional non-implemented functionality
                // will fall to default case
            case OutputTarget::STDOUT:
            default:
                return std::make_shared<StdOutLogger::StdOutLogger>();
        }
    }
}