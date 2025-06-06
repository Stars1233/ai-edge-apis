// Copyright 2025 The Google AI Edge Authors.
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

#include "local_agents/utils/core/ret_check.h"

#include "absl/status/status.h"  // from @abseil-cpp
#include "local_agents/utils/core/source_location.h"
#include "local_agents/utils/core/status_builder.h"

namespace odml::genai_modules {

StatusBuilder RetCheckFailSlowPath(
    odml::genai_modules::source_location location) {
  return InternalErrorBuilder(location)
         << "RET_CHECK failure (" << location.file_name() << ":"
         << location.line() << ") ";
}

StatusBuilder RetCheckFailSlowPath(
    odml::genai_modules::source_location location, const char* condition) {
  return RetCheckFailSlowPath(location) << condition;
}

StatusBuilder RetCheckFailSlowPath(
    odml::genai_modules::source_location location, const char* condition,
    const absl::Status& status) {
  return RetCheckFailSlowPath(location)
         << condition << " returned " << status << " ";
}

}  // namespace odml::genai_modules
