#pragma once
#include <string_view>
#include <string>
#include <memory>
#include "LoggingFacility.h"

namespace LoggerFactory
{
    class LoggerFactory
    {
        public:
            explicit LoggerFactory(std::string_view configurationFileName) : configurationFileName { configurationFileName }
            { }

            [[nodiscard]] std::shared_ptr<LoggingFacility::LoggingFacility> create() const;

        private:
            enum class OutputTarget : int 
            {
                STDOUT,
                FILE
            };

            std::string configurationFileName;

            [[nodiscard]] std::string readConfigurationFile(std::string configurationFileName) const;
            [[nodiscard]] OutputTarget evaluateConfiguration(std::string configurationFileContent) const;
            [[nodiscard]] std::shared_ptr<LoggingFacility::LoggingFacility> createLogger(LoggerFactory::OutputTarget outputTarget) const;
    };
}