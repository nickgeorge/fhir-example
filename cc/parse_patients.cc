#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_cat.h"
#include "absl/time/time.h"
#include "google/fhir/json_format.h"
#include "proto/r4/core/resources/patient.pb.h"
#include "cc/example_utils.h"

using std::string;

using ::google::fhir::JsonFhirStringToProto;
using ::google::fhir::PrintFhirToJsonStringForAnalytics;
using ::google::fhir::r4::core::Patient;

int main(int argc, char** argv) {
  absl::TimeZone time_zone;
  CHECK(absl::LoadTimeZone("America/Los_Angeles", &time_zone));

  const std::vector<Patient>& result =
  		fhir_examples::ReadNdJsonFile<Patient>(
  			time_zone, absl::StrCat(argv[1]));

  std::cout << result.front().DebugString() << std::endl;
}
