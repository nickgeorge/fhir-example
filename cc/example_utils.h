#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_cat.h"
#include "absl/time/time.h"
#include "google/fhir/json_format.h"
#include "proto/r4/core/resources/patient.pb.h"

namespace fhir_examples {

template <typename R>
std::vector<R> ReadNdJsonFile(const absl::TimeZone& time_zone, std::string filename) {
  std::ifstream read_stream;
  read_stream.open(absl::StrCat(filename));

  std::vector<R> result;
  std::string line;
  while (!read_stream.eof()) {
    std::getline(read_stream, line);
    if (!line.length()) continue;
    result.push_back(
      ::google::fhir::JsonFhirStringToProto<R>(line, time_zone)
          .ValueOrDie());
  }
  return result;
}

}  // namespace fhir_examples