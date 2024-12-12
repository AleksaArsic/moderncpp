# Project information
cmake_minimum_required(VERSION 3.15)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(ArabicToRomanNumeralsConverterUnitTests VERSION 1.0.0)

add_library(ArabicToRomanNumeralsConverter ../src/ArabicToRomanNumeralsConverter.cpp)
target_include_directories(ArabicToRomanNumeralsConverter PUBLIC ../include)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test cpp file(s) 
add_executable(ArabicToRomanNumeralsConverterTestCase ArabicToRomanNumeralsConverterTestCase.cpp)

#Link test executable against gtest and gtest_main
target_link_libraries(ArabicToRomanNumeralsConverterTestCase ArabicToRomanNumeralsConverter gtest gtest_main)

add_test(NAME ArabicToRomanNumeralsConverterTestCase_test COMMAND ArabicToRomanNumeralsConverterTestCase)

