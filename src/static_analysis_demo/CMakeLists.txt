find_package(GTest REQUIRED)

set(SOURCES
    classDemo.cpp
)

add_library(classDemo
    STATIC
    ${SOURCES}
)

include(GoogleTest)
add_executable(classDemo_test classDemo_test.cpp)
target_link_libraries(classDemo_test classDemo GTest::gtest GTest::gtest_main GTest::gmock_main)
gtest_add_tests(classDemo_test
    "" AUTO
)
