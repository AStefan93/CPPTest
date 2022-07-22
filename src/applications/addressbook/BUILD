# cc_binary(
#     name = "addressbook_client",
#     srcs = ["addressbook_client.cpp"],
#     defines = ["BAZEL_BUILD"],
#     deps = [
#         ":addressbook_cc_grpc",
#         "@com_github_grpc_grpc//:grpc++",
#     ],
# )

cc_binary(
    name = "addressbook_server",
    srcs = ["addressbook_server.cpp"],
    deps = [
        # ":addressbook_cc_grpc",
        # "@com_github_grpc_grpc//:grpc++",
    ],
)

cc_library(
    name = "addressbook",
    srcs = ["addressbook.cpp"],
    hdrs = ["addressbook.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//external_interface/addressbook:addressbook_cc_proto",
    ],
)

cc_test(
    name = "addressbook_test",
    srcs = ["addressbook_test.cpp"],
    deps = [
        "addressbook",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "addressbook_test_integration",
    srcs = ["addressbook_test_integration.cpp"],
    deps = [
        "addressbook",
        "@googletest//:gtest_main",
    ],
)
