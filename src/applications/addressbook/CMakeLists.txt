# install protobuf
conan_cmake_configure(REQUIRES protobuf/3.21.12
    GENERATORS CMakeToolchain CMakeDeps)
conan_cmake_install(PATH_OR_REFERENCE .
    OUTPUT_FOLDER ${PROJECT_BINARY_DIR}
    BUILD missing
    PROFILE_BUILD ${PROJECT_SOURCE_DIR}/conan/GCC${CMAKE_BUILD_TYPE}
    PROFILE_HOST ${PROJECT_SOURCE_DIR}/conan/GCC${CMAKE_BUILD_TYPE}
    REMOTE conancenter)

# Generate proto lib
find_package(protobuf REQUIRED)
set(PROTO_DIR ${PROJECT_SOURCE_DIR}/external_interface/addressbook)
set(SOURCES
    ${PROTO_DIR}/addressbook.proto
)
add_library(addressbook_proto
    STATIC
    ${SOURCES}
)
target_link_libraries(addressbook_proto protobuf::libprotobuf)
set(PROTO_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}")
target_include_directories(addressbook_proto PUBLIC "$<BUILD_INTERFACE:${PROTO_BINARY_DIR}>")
protobuf_generate(
    TARGET addressbook_proto
    IMPORT_DIRS "${PROTO_DIR}"
    PROTOC_OUT_DIR "${PROTO_BINARY_DIR}")

# compile application
find_package(GTest REQUIRED)
set(SOURCES
    addressbook.cpp
)
add_library(addressbook
    STATIC
    ${SOURCES}
)
target_link_libraries(addressbook addressbook_proto)
target_compile_options(addressbook PRIVATE -Wall -Wextra -Wpedantic)

# compile tests
include(GoogleTest)
add_executable(addressbook_test addressbook_test.cpp)
target_link_libraries(addressbook_test addressbook GTest::gtest GTest::gtest_main)
gtest_add_tests(addressbook_test
    "" AUTO
)
