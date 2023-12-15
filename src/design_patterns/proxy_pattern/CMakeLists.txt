find_package(GTest REQUIRED)

set(TARGET proxy_pattern)
set(SOURCES
    ${TARGET}.cpp
)
add_library(${TARGET}
    STATIC
    ${SOURCES}
)
target_compile_options(${TARGET} PRIVATE -Wall -Wextra -Wpedantic)

include(GoogleTest)
add_executable(${TARGET}_test ${TARGET}_test.cpp)
target_link_libraries(${TARGET}_test ${TARGET} GTest::gtest GTest::gtest_main)
gtest_add_tests(${TARGET}_test
    "" AUTO
)
