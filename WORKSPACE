# Standard Bazel Tools
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# Protocol Buffers
# rules_proto defines abstract rules for building Protocol Buffers.
http_archive(
    name = "rules_proto",
    sha256 = "66bfdf8782796239d3875d37e7de19b1d94301e8972b3cbd2446b332429b4df1",
    strip_prefix = "rules_proto-4.0.0",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/refs/tags/4.0.0.tar.gz",
    ],
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
http_archive(
    name = "hedron_compile_commands",
    sha256 = "10b5f7a36252ce0dd3396c289ba0138779adb6436c187266f6a93de505f3434f",
    strip_prefix = "bazel-compile-commands-extractor-07c307ab34d458cf0a4187a15ce1f6a2b72c408c",

    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/07c307ab34d458cf0a4187a15ce1f6a2b72c408c.tar.gz",
    # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'hedron_compile_commands' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()

# Google Test
git_repository(
    name = "googletest",
    commit = "e2239ee6043f73722e7aa812a459f54a28552929",
    remote = "https://github.com/google/googletest",
    shallow_since = "1623433346 -0700",
)

# gRPC
http_archive(
    name = "com_github_grpc_grpc",
    sha256 = "8bd976b27ac303845e1a54ec5912f39058b1b53fd43272d1d27d8a1ce5915adf",
    strip_prefix = "grpc-febed5121a82ff05a8bf29003c0935507c45a530",
    urls = [
        "https://github.com/grpc/grpc/archive/febed5121a82ff05a8bf29003c0935507c45a530.tar.gz",
    ],
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()

# Include what you use
git_repository(
    name = "com_github_storypku_bazel_iwyu",
    commit = "94c6e95c8cfeb8596b46b6dd13bb41c56fb41f74",
    remote = "https://github.com/storypku/bazel_iwyu",
    shallow_since = "1657478630 +0800",
)

load("@com_github_storypku_bazel_iwyu//bazel:dependencies.bzl", "bazel_iwyu_dependencies")

bazel_iwyu_dependencies()
