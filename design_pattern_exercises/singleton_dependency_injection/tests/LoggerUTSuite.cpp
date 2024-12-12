#include <gtest/gtest.h>
#include <string>
#include <string_view>
#include "CustomerRepository.h"
#include "LoggingFacility.h"
#include "mocks/include/MockedLogger.h"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(CustomerTestCase, WrittenLogEntryIsAsExpected)
{
    std::shared_ptr<MockedLogger::MockedLogger> mockedLogger = std::make_shared<MockedLogger::MockedLogger>();

    CustomerRepository::CustomerRepository customerRepository{ mockedLogger };

    customerRepository.findCustomerById(0);

    std::string expectedLoggedString = "Start searching customer by a specific identifier.";

    ASSERT_EQ(expectedLoggedString, mockedLogger->getRecentlyWrittenLog());
}