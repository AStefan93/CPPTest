find_package(protobuf REQUIRED)

set(SOURCES
    addressbook.proto
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
    IMPORT_DIRS "${CMAKE_CURRENT_LIST_DIR}"
    PROTOC_OUT_DIR "${PROTO_BINARY_DIR}")
