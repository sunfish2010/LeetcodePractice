load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "union_find",
    hdrs = ["union_find.hh"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":union_find"
    ],
)
