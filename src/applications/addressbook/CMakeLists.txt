find_package(GTest REQUIRED)

set(SOURCES
    addressbook.cpp
)

add_library(addressbook
    STATIC
    ${SOURCES}
)

include(GoogleTest)
add_executable(addressbook_test addressbook_test.cpp)
target_link_libraries(addressbook_test addressbook GTest::gtest GTest::gtest_main)
gtest_add_tests(addressbook_test
    "" AUTO
)
