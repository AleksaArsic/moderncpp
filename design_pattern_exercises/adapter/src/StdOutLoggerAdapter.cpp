#include "StdOutLoggerAdapter.h"

namespace StdOutLoggerAdapter
{
    void StdOutLoggerAdapter::setComponentId(const unsigned int id)
    {
        componentId = id;
    }

    void StdOutLoggerAdapter::stdOutLogInfo(std::string_view logInformation)
    {
        stdOutLoggerPtr->stdOutLogInfo(componentId, logInformation);
    }

    void StdOutLoggerAdapter::stdOutLogWarning(std::string_view logWarning)
    {
        stdOutLoggerPtr->stdOutLogWarning(componentId, logWarning);
    }

    void StdOutLoggerAdapter::stdOutLogError(std::string_view logError)
    {
        stdOutLoggerPtr->stdOutLogError(componentId, logError);
    }  
}