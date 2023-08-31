
find_package(GTest REQUIRED)

set(SOURCES
    Hello.cpp
)

add_library(hello_library
    STATIC
    ${SOURCES}
)

add_executable(hello_library_test Hello_test.cpp)
target_link_libraries(hello_library_test hello_library GTest::gtest GTest::gtest_main)
gtest_add_tests(hello_library_test
    "" AUTO
)
