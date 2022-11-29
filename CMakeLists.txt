cmake_minimum_required(VERSION 3.14)

project(let2)

set(CMAKE_CXX_STANDARD 17)

# флаг, который подключает тесты к проекту
set(ENABLE_UNIT_TESTS ON)

set(HEADERS_DIR Headers)
set(SOURCES_DIR Sources)
set(TEST_DIR Tests)

include_directories(${HEADERS_DIR})

find_package(Threads REQUIRED)

set(HEADERS
    ${HEADERS_DIR}/Cell.h
    ${HEADERS_DIR}/IntGenerator.h
    ${HEADERS_DIR}/multiplyFunctions.h
)

set(SOURCES
    ${SOURCES_DIR}/multiplyFunctions.cpp
    ${SOURCES_DIR}/IntGenerator.cpp
)

add_executable(${PROJECT_NAME}
    ${SOURCES_DIR}/main.cpp
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME}
    Threads::Threads
)

if (ENABLE_UNIT_TESTS)

    include(FetchContent)
    include(GoogleTest)
    enable_testing()

    FetchContent_Declare(
      googletest
      GIT_REPOSITORY https://github.com/google/googletest.git
      GIT_TAG        release-1.12.1
    )

    FetchContent_MakeAvailable(googletest)

    set(TEST_SOURCES
        ${TEST_DIR}/tests.cpp
        ${SOURCES}
        ${HEADERS}
    )

    set(TEST_PROJECT_NAME let2-test)

    add_executable(${TEST_PROJECT_NAME} ${TEST_SOURCES})

    target_link_libraries(${TEST_PROJECT_NAME}
        PRIVATE gtest_main
    )

    include_directories(${HEADERS_DIR})

endif()
