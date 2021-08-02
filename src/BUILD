cc_library(
    name = "test",
    srcs = ["test.cpp"],
    hdrs = ["test.hpp"],
    deps = [
        "//src/array:array",
    ],
    visibility = ["//:__pkg__"],
)

cc_test(
    name = "test1",
    srcs = ["test1.cpp"],
    deps = [
        "@googletest//:gtest_main",
        "//src:test",
    ]
)
