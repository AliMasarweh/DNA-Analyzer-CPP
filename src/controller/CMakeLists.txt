cmake_minimum_required(VERSION 3.15)
project(DNA_Controller)

set(CMAKE_CXX_STANDARD 98)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(DNA_Controller controller.h)
target_link_libraries(DNA_Controller gtest gtest_main pthread)
