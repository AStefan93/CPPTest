load("@rules_proto//proto:defs.bzl", "proto_library")

proto_library(
    name = "addressbook",
    srcs = ["addressbook.proto"],
)

cc_proto_library(
    name = "addressbook_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":addressbook"],
)
