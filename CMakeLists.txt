cmake_minimum_required(VERSION 3.15)
project(DNAnalyzer)

set(CMAKE_CXX_STANDARD 98)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(cmd cmd.cpp databaseHandler/database_handler.cpp testingUnit/test_dnanalyzer.cpp)
add_executable(DNAnalyzer databaseHandler/database_handler.cpp)

add_executable(testDNAnalyzer testingUnit/test_dnanalyzer.cpp)
target_link_libraries(testDNAnalyzer gtest gtest_main pthread)
