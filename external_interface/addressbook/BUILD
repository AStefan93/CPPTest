load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")

proto_library(
    name = "addressbook",
    srcs = ["addressbook.proto"],
)

cc_proto_library(
    name = "addressbook_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":addressbook"],
)

# cc_grpc_library(
#     name = "addressbook_cc_grpc",
#     srcs = [":addressbook"],
#     grpc_only = True,
#     deps = [":addressbook_cc_proto"],
# )
