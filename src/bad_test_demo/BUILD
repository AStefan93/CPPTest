cc_library(
    name = "math_equations",
    srcs = ["math_equations.cpp"],
    hdrs = [
        "math_equations.hpp",
    ],
    visibility = ["//src:__pkg__"],
)

cc_test(
    name = "math_equations_test",
    srcs = ["math_equations_test.cpp"],
    deps = [
        "math_equations",
        "@googletest//:gtest_main",
    ],
)
