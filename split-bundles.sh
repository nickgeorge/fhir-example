if [[ $# -eq 0 ]] ; then
    echo 'Missing argument: scratch directory'
    exit 1
fi

bazel build @com_google_fhir//java:SplitBundle

SPLIT_BUNDLE=$(pwd)/../../bazel-bin/java/SplitBundle

cd $1