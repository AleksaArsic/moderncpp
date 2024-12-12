#include "MockedLogger.h"
#include <string>
#include <string_view>

namespace MockedLogger
{

    void MockedLogger::stdOutLogInfo(std::string_view logInformation)
    {
        recentlyWrittenLog = logInformation;
    }

    void MockedLogger::stdOutLogWarning(std::string_view logWarning)
    {
        recentlyWrittenLog = logWarning;
    }

    void MockedLogger::stdOutLogError(std::string_view logError)
    {
        recentlyWrittenLog = logError;
    }

    [[nodiscard]] std::string_view MockedLogger::getRecentlyWrittenLog() const
    {
        return recentlyWrittenLog;
    }
}