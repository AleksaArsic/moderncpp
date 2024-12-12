#include "LoggerSingleton.h"

namespace LoggerSingleton
{

    [[nodiscard]] LoggerSingleton& LoggerSingleton::getLogger()
    {
        static LoggerSingleton logger;

        return logger;
    }

    void LoggerSingleton::stdOutLogInfo(std::string_view logInformation) const
    {
        std::cout << "[INFO]: " << logInformation << std::endl;
    }

    void LoggerSingleton::stdOutLogWarning(std::string_view logWarning) const
    {
        std::cout << "[WARNING]: " << logWarning << std::endl;
    }

    void LoggerSingleton::stdOutLogError(std::string_view logError) const
    {
        std::cout << "[ERROR]: " << logError << std::endl;
    }
}