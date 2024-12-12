#include <string>
#include <string_view>
#include "CustomerRepository.h"
#include "LoggingFacility.h"

namespace MockedLogger
{
    class MockedLogger : public LoggingFacility::LoggingFacility
    {
        public:
            virtual void stdOutLogInfo(std::string_view logInformation) override final;

            virtual void stdOutLogWarning(std::string_view logWarning) override final;
            virtual void stdOutLogError(std::string_view logError) override final;
            [[nodiscard]] std::string_view getRecentlyWrittenLog() const;

        private:
            std::string recentlyWrittenLog;
    };
}