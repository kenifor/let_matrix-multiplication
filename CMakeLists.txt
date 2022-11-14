cmake_minimum_required(VERSION 3.14)

project(let2)

set(CMAKE_CXX_STANDARD 17)

# флаг, который подключает тесты к проекту
set(ENABLE_UNIT_TESTS ON)

#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

set(HEADERS_DIR Headers)
set(SOURCES_DIR Sources)
set(TEST_DIR Tests)

include_directories(${HEADERS_DIR})

set(FILES
    ${HEADERS_DIR}/multiplyFunctions.h
    ${SOURCES_DIR}/multiplyFunctions.cpp
    ${SOURCES_DIR}/main.cpp
    ${SOURCES_DIR}/IntGenerator.cpp
    ${HEADERS_DIR}/IntGenerator.h
)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${FILES})

target_link_libraries(${PROJECT_NAME}
    Threads::Threads)

if (ENABLE_UNIT_TESTS)

    #set(GTEST_INCLUDE_DIR lib/)
    #find_package(GTest REQUIRED)

    include(FetchContent)
    include(GoogleTest)
    enable_testing()
    #gtest_discover_tests(${TEST_PROJECT_NAME})

    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        release-1.12.1
    )

    FetchContent_MakeAvailable(googletest)

    set(TEST_SOURCES
        ${TEST_DIR}/tests.cpp
        ${HEADERS_DIR}/multiplyFunctions.h
        ${SOURCES_DIR}/multiplyFunctions.cpp
        ${SOURCES_DIR}/IntGenerator.cpp
        ${HEADERS_DIR}/IntGenerator.h
    )

    set(TEST_PROJECT_NAME let2-test)

    add_executable(${TEST_PROJECT_NAME} ${TEST_SOURCES})

    target_link_libraries(${TEST_PROJECT_NAME}
        PRIVATE gtest_main)

    include_directories(${HEADERS_DIR})

    #gtest_discover_tests(${TEST_PROJECT_NAME} AUTO)

endif()
