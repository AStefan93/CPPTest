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
