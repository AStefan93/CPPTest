
# include(${PROJECT_BINARY_DIR}/conan.cmake)
# conan_cmake_configure(REQUIRES grpc and protobuf?
#     GENERATORS CMakeToolchain CMakeDeps)
# conan_cmake_install(PATH_OR_REFERENCE .
#     OUTPUT_FOLDER ${PROJECT_BINARY_DIR}
#     BUILD missing
#     PROFILE_BUILD ${PROJECT_SOURCE_DIR}/conan/GCC${CMAKE_BUILD_TYPE}
#     PROFILE_HOST ${PROJECT_SOURCE_DIR}/conan/GCC${CMAKE_BUILD_TYPE}
#     REMOTE conancenter
# )
# include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

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
