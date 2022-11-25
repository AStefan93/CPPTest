cc_library(
    name = "classDemo",
    srcs = ["classDemo.cpp"],
    hdrs = [
        "classDemo.hpp",
        "classDemoInterface.hpp",
    ],
    visibility = ["//src:__pkg__"],
)

cc_test(
    name = "classDemo_test",
    srcs = ["classDemo_test.cpp"],
    deps = [
        "classDemo",
        "@googletest//:gtest_main",
    ],
)
