find_package(GTest REQUIRED)

set(SOURCES
    array.cpp
)

add_library(array
    STATIC
    ${SOURCES}
)

include(GoogleTest)
add_executable(array_test array_test.cpp)
target_link_libraries(array_test array GTest::gtest GTest::gtest_main GTest::gmock_main)
gtest_add_tests(array_test
    "" AUTO
)
