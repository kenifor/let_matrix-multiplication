cmake_minimum_required(VERSION 3.16)

project(Test)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)

set(MAIN_PROJECT_HEADERS_DIR ../Headers)
set(MAIN_PROJECT_SOURCES_DIR ../Sources)

set(SOURCES
    tests.cpp
    ${MAIN_PROJECT_HEADERS_DIR}/multiplyFunctions.h
    ${MAIN_PROJECT_SOURCES_DIR}/multiplyFunctions.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${MAIN_PROJECT_HEADERS_DIR})

target_link_libraries(${PROJECT_NAME} gtest_main)

#enable_testing()

#include(GoogleTest)
#gtest_discover_tests(${PROJECT_NAME})
