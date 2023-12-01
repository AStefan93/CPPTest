find_package(GTest REQUIRED)

set(TARGET array)

set(SOURCES
    array.cpp
)

add_library(${TARGET}
    STATIC
    ${SOURCES}
)
target_compile_options(${TARGET} PRIVATE -Wall -Wextra -Wpedantic)

include(GoogleTest)
add_executable(${TARGET}_test array_test.cpp)
target_link_libraries(${TARGET}_test ${TARGET} GTest::gtest GTest::gtest_main GTest::gmock_main)
gtest_add_tests(${TARGET}_test
    "" AUTO
)
