load("@rules_cc//cc:defs.bzl", "cc_library", "cc_binary")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hash_table",
    hdrs = ["hash_table.hh"],
)


cc_library(
    name = "sc_hash",
    hdrs = ["sc_hash.hh"],
    deps = [
        ":hash_table"
    ],
)


cc_binary(
    name = "test_hash_table",
    srcs = ["test_hash_table.cc"],
    deps = [
        ":sc_hash"
    ],
)
