if [[ $# -eq 0 ]] ; then
    echo 'Missing argument: scratch directory'
    exit 1
fi

mkdir -p $1
pushd $1

# build synthea according to https://github.com/synthetichealth/synthea
git clone https://github.com/synthetichealth/synthea.git
cd synthea

# generate 1000 valid R4 bundles in output/fhir/
./run_synthea Massachusetts -p 1000

popd

mkdir $1/synthea/outpout/split/
bazel build @com_google_fhir//java:SplitBundle
bazel-bin/external/fhirproto/java/SplitBundle $1/synthea/outpout/split/ $1/synthea/output/fhir/*.json