find_package(GTest REQUIRED)

set(SOURCES
    math_equations.cpp
)

add_library(math_equations
    STATIC
    ${SOURCES}
)

include(GoogleTest)
add_executable(math_equations_test math_equations_test.cpp)
target_link_libraries(math_equations_test math_equations GTest::gtest GTest::gtest_main GTest::gmock_main)
gtest_add_tests(math_equations_test
    "" AUTO
)
