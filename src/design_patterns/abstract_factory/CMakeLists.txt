find_package(GTest REQUIRED)

set(SOURCES
    abstract_factory.cpp
    maze.cpp
)

add_library(abstract_factory
    STATIC
    ${SOURCES}
)

include(GoogleTest)
add_executable(abstract_factory_test abstract_factory_test.cpp)
target_link_libraries(abstract_factory_test abstract_factory GTest::gtest GTest::gtest_main)
gtest_add_tests(abstract_factory_test
    "" AUTO
)
