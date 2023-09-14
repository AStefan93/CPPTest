if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake"
        TLS_VERIFY ON)
endif()

include(${PROJECT_BINARY_DIR}/conan.cmake)
conan_cmake_configure(REQUIRES gtest/cci.20210126
    GENERATORS CMakeToolchain CMakeDeps)
conan_cmake_install(PATH_OR_REFERENCE .
    OUTPUT_FOLDER ${PROJECT_BINARY_DIR}
    BUILD missing
    PROFILE_BUILD ${PROJECT_SOURCE_DIR}/conan/GCC${CMAKE_BUILD_TYPE}
    PROFILE_HOST ${PROJECT_SOURCE_DIR}/conan/GCC${CMAKE_BUILD_TYPE}
    REMOTE conancenter
)
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(GTest REQUIRED)

set(SOURCES
    Hello.cpp
)

add_library(hello_library
    STATIC
    ${SOURCES}
)

include(GoogleTest)
add_executable(hello_library_test Hello_test.cpp)
target_link_libraries(hello_library_test hello_library GTest::gtest GTest::gtest_main)
gtest_add_tests(hello_library_test
    "" AUTO
)
