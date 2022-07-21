# Standard Bazel Tools
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

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
    sha256 = "4a1712a3319ddb97c1b215e9927787344b4fddaafc4ea166cf3095a767b02986",
    strip_prefix = "bazel-compile-commands-extractor-a36dd55381f5bc452aa9f5392a8f8472a6270450",

    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/a36dd55381f5bc452aa9f5392a8f8472a6270450.tar.gz",
    # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'hedron_compile_commands' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()

# Google Test
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "googletest",
    commit = "e2239ee6043f73722e7aa812a459f54a28552929",
    remote = "https://github.com/google/googletest",
    shallow_since = "1623433346 -0700",
)

# QT
git_repository(
    name = "com_justbuchanan_rules_qt",
    commit = "3196fcf2e6ee81cf3a2e2b272af3d4259b84fcf9",
    remote = "https://github.com/justbuchanan/bazel_rules_qt.git",
    shallow_since = "1645077947 -0800",
)

load("@com_justbuchanan_rules_qt//:qt_configure.bzl", "qt_configure")

qt_configure()

load("@local_config_qt//:local_qt.bzl", "local_qt_path")

new_local_repository(
    name = "qt",
    build_file = "@com_justbuchanan_rules_qt//:qt.BUILD",
    path = local_qt_path(),
)

load("@com_justbuchanan_rules_qt//tools:qt_toolchain.bzl", "register_qt_toolchains")

register_qt_toolchains()

# gRPC
http_archive(
    name = "com_github_grpc_grpc",
    sha256 = "883afadf0545fbeceab40b5c77c931207189eec87dabcb9ed5f4cef8670d03a5",
    strip_prefix = "grpc-a1d42f84efcd339ecadfa5a87fbd229d43cb45bb",
    urls = [
        "https://github.com/grpc/grpc/archive/a1d42f84efcd339ecadfa5a87fbd229d43cb45bb.tar.gz",
    ],
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()
