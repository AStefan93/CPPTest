load("@com_justbuchanan_rules_qt//:qt.bzl", "qt_cc_library", "qt_ui_library")

cc_binary(
    name = "copilot_demo_main",
    srcs = ["copilot_demo_main.cpp"],
    deps = [
        ":copilot_demo",
        ":copilot_demo_mainwindow",
        "@qt//:qt_widgets",
    ],
)

qt_cc_library(
    name = "copilot_demo",
    srcs = ["copilot_demo.cpp"],
    hdrs = ["copilot_demo.hpp"],
    deps = ["@qt//:qt_widgets"],
)

qt_ui_library(
    name = "copilot_demo_mainwindow",
    ui = "copilot_demo_mainwindow.ui",
    deps = ["@qt//:qt_widgets"],
)
