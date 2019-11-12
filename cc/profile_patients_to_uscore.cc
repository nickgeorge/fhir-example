// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_cat.h"
#include "absl/time/time.h"
#include "google/fhir/json_format.h"
#include "google/fhir/r4/profiles.h"
#include "proto/r4/core/resources/patient.pb.h"
#include "proto/r4/uscore.pb.h"
#include "cc/example_utils.h"

using std::string;

using ::google::fhir::JsonFhirStringToProto;
using ::google::fhir::PrintFhirToJsonStringForAnalytics;
using ::google::fhir::r4::core::Patient;
using ::google::fhir::r4::uscore::USCorePatientProfile;

int main(int argc, char** argv) {
  absl::TimeZone time_zone;
  CHECK(absl::LoadTimeZone("America/Los_Angeles", &time_zone));

  const std::vector<Patient>& patients =
  		fhir_examples::ReadNdJsonFile<Patient>(
  			  time_zone, absl::StrCat(argv[1]));

  std::vector<USCorePatientProfile> uscore_patients;
  for (const Patient& patient : patients) {
    uscore_patients.emplace_back();
    google::fhir::ConvertToProfileR4(patient, &uscore_patients.back());
  }

  std::cout << uscore_patients.front().DebugString() << std::endl;
}
