cmake_minimum_required(VERSION 3.22.1)
project(Tutorial VERSION 1.0)

set(SOURCES
    src/Tutorial/Hello.cpp
    src/Tutorial/main.cpp
)
add_executable(Tutorial ${SOURCES})

target_include_directories(Tutorial
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src/Tutorial
)