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
    sha256 = "11cdd4edb158b2c4a7644d6b2f246e3fc4ac39dc8c0111a5677a03fc655ccbb2",
    strip_prefix = "bazel-compile-commands-extractor-a8be2f874ceea265724d9581f3d0c9b58a9ba73f",

    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/a8be2f874ceea265724d9581f3d0c9b58a9ba73f.tar.gz",
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
    sha256 = "da1ce52a77a54b2a70bd6d506330bd09bc6a10828e41ef60b4ed84f2c69fc784",
    strip_prefix = "grpc-ed0ebb837e769d26be58033539acad0d73835255",
    urls = [
        "https://github.com/grpc/grpc/archive/ed0ebb837e769d26be58033539acad0d73835255.tar.gz",
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
