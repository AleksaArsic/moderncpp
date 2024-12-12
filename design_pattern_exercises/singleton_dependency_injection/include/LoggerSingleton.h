#pragma once 
#include <string_view>
#include <iostream>

namespace LoggerSingleton
{
    class LoggerSingleton
    {
        public:
            [[nodiscard]] static LoggerSingleton& getLogger();

            void stdOutLogInfo(std::string_view logInformation) const;
            void stdOutLogWarning(std::string_view logWarning) const;
            void stdOutLogError(std::string_view logError) const;

        private:
            LoggerSingleton() = default;

            LoggerSingleton(const LoggerSingleton& logger) = delete;
            LoggerSingleton(const LoggerSingleton&& logger) = delete;
            LoggerSingleton& operator=(const LoggerSingleton& logger) = delete;
            LoggerSingleton&& operator=(const LoggerSingleton&& logger) = delete;
    };
}