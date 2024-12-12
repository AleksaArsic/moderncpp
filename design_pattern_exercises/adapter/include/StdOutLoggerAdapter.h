#pragma once
#include <string_view>
#include <iostream>
#include <memory>
#include "LoggingFacility.h"
#include "StdOutLogger.h"

namespace StdOutLoggerAdapter
{
    class StdOutLoggerAdapter : public LoggingFacility::LoggingFacility
    {
        public:
            StdOutLoggerAdapter()
            {
                stdOutLoggerPtr = std::make_unique<StdOutLogger::StdOutLogger>();
                componentId = 0;
            }

            void setComponentId(const unsigned int id);

            virtual void stdOutLogInfo(std::string_view logInformation) override;
            virtual void stdOutLogWarning(std::string_view logWarning) override;
            virtual void stdOutLogError(std::string_view logError) override;
        private:
            std::unique_ptr<StdOutLogger::StdOutLogger> stdOutLoggerPtr;
            unsigned int componentId;
    };
}