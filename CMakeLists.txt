cmake_minimum_required(VERSION 3.15)
project(DNAnalyzer)

set(CMAKE_CXX_STANDARD 98)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(cmd cmd.cpp database_handler.cpp test_dnanalyzer.cpp)
add_executable(db database_handler.cpp)

add_executable(testDNAnalyzer test_dnanalyzer.cpp)
target_link_libraries(testDNA_Sequence gtest gtest_main pthread)
