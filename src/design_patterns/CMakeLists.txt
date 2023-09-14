find_package(GTest REQUIRED)

set(SOURCES
    observer_pattern.cpp
)

add_library(observer_pattern
    STATIC
    ${SOURCES}
)

include(GoogleTest)
add_executable(observer_pattern_test observer_pattern_test.cpp)
target_link_libraries(observer_pattern_test observer_pattern GTest::gtest GTest::gtest_main)
gtest_add_tests(observer_pattern_test
    "" AUTO
)
