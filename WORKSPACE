workspace(name = "com_nickjpgeorge_fhirprotoexamples")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_jvm_external",
    strip_prefix = "rules_jvm_external-2.1",
    sha256 = "515ee5265387b88e4547b34a57393d2bcb1101314bcc5360ec7a482792556f42",
    url = "https://github.com/bazelbuild/rules_jvm_external/archive/2.1.zip",
)

http_archive(
    name = "io_bazel_rules_closure",
    sha256 = "7d206c2383811f378a5ef03f4aacbcf5f47fd8650f6abbc3fa89f3a27dd8b176",
    strip_prefix = "rules_closure-0.10.0",
    urls = [
        "https://github.com/bazelbuild/rules_closure/archive/0.10.0.tar.gz",
    ],
)

http_archive(
    name = "rules_python",
    sha256 = "fa53cc0afe276d8f6675df1a424592e00e4f37b2a497e48399123233902e2e76",
    strip_prefix = "rules_python-0.0.1",
    urls = ["https://github.com/bazelbuild/rules_python/archive/0.0.1.tar.gz"],
)

http_archive(
    name = "org_tensorflow",
    sha256 = "49b5f0495cd681cbcb5296a4476853d4aea19a43bdd9f179c928a977308a0617",
    strip_prefix = "tensorflow-2.0.0",
    urls = [
        "https://github.com/tensorflow/tensorflow/archive/v2.0.0.tar.gz",
    ],
)

http_archive(
    name = "com_google_fhir",
    sha256 = "06cae84ae527682825b838d3c7c27152109ee0a589b4ed6235f9ed3fba92afce",
    strip_prefix = "fhir-5dd3aefcffee5215f2eea278fa3cebc8cc3db1dd",
    urls = [
        "https://github.com/google/fhir/archive/5dd3aefcffee5215f2eea278fa3cebc8cc3db1dd.zip",
    ],
)

load("@rules_python//python:pip.bzl", "pip_import")

pip_import(
    name = "fhir_bazel_pip_dependencies",
    requirements = "@com_google_fhir//bazel:requirements.txt",
)


load("@com_google_fhir//bazel:dependencies.bzl", "fhir_proto_dependencies")
fhir_proto_dependencies()
