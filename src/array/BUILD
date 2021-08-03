cc_library(
    name = "array",
    srcs = ["array.cpp"],
    hdrs = ["array.hpp"],
    visibility = ["//src:__pkg__"],
)

cc_test(
    name = "array_test",
    srcs = ["array_test.cpp"],
    deps = [
        "@googletest//:gtest_main",
        "array"
    ]
)
