load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
http_archive(
    name = "hedron_compile_commands",

    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here. 
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/28b2d608bcbc8452072fee2a8600be4b31d8b491.tar.gz",
    strip_prefix = "bazel-compile-commands-extractor-28b2d608bcbc8452072fee2a8600be4b31d8b491",
    sha256 = "ae296eed71a20dfae0bd6fa38cc18c1937c0bbdd7ea880951e3cc32992857da2"
    # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'hedron_compile_commands' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..." 
)
load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")
hedron_compile_commands_setup()

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
  name = "googletest",
  remote = "https://github.com/google/googletest",
  tag = "release-1.11.0",
)