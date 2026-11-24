CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project(Leetcode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB LEETCODE_SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*/solution.cpp)

add_library(leetcode OBJECT ${LEETCODE_SOURCES})

target_include_directories(leetcode PUBLIC ${CMAKE_SOURCE_DIR}/third_party)

if (NOT MSVC) 
    target_compile_options(leetcode PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(leetcode_tests tests/main.cpp)
target_link_libraries(leetcode_tests PRIVATE leetcode)


enable_testing()
add_test(NAME leetcode COMMAND leetcode_tests)

