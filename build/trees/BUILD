load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "search_tree",
    hdrs = ["search_tree.hh"],
)

cc_library(
    name = "bst",
    hdrs = ["bst.hh"],
    deps = [
        ":search_tree"
    ],
)


cc_binary(
    name = "test_search_trees",
    srcs = ["test_search_trees.cc"],
    deps = [
        ":bst"
    ],
)
