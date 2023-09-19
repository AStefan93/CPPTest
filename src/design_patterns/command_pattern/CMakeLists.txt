find_package(GTest REQUIRED)

set(SOURCES
    command_pattern.cpp
)

add_library(command_pattern
    STATIC
    ${SOURCES}
)

include(GoogleTest)
add_executable(command_pattern_test command_pattern_test.cpp)
target_link_libraries(command_pattern_test command_pattern GTest::gtest GTest::gtest_main)
gtest_add_tests(command_pattern_test
    "" AUTO
)
