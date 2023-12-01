# Call Conan Install
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
        "${CMAKE_BINARY_DIR}/conan.cmake"
        TLS_VERIFY ON)
endif()

include(${PROJECT_BINARY_DIR}/conan.cmake)
conan_cmake_configure(REQUIRES protobuf/3.21.12
    GENERATORS CMakeToolchain CMakeDeps)
conan_cmake_install(PATH_OR_REFERENCE .
    OUTPUT_FOLDER ${PROJECT_BINARY_DIR}
    BUILD missing
    PROFILE_BUILD ${PROJECT_SOURCE_DIR}/conan/GCC${CMAKE_BUILD_TYPE}
    PROFILE_HOST ${PROJECT_SOURCE_DIR}/conan/GCC${CMAKE_BUILD_TYPE}
    REMOTE conancenter
)
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

add_subdirectory(addressbook)

