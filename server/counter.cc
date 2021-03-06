/* <server/counter.cc> 

   Implements <server/counter.h>.

   Copyright 2010-2014 Tagged
   
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
   
     http://www.apache.org/licenses/LICENSE-2.0
   
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

#include <server/counter.h>

using namespace Base;
using namespace Server;

TCounter::TCounter(const TCodeLocation &code_location, const char *name)
    : CodeLocation(code_location), Name(name), UnsampledCount(0), SampledCount(0) {
  assert(name);
  NextCounter = FirstCounter;
  FirstCounter = this;
}

time_t TCounter::Reset() {
  ResetTime = time(0);
  for (TCounter *counter = FirstCounter; counter; counter = counter->NextCounter) {
    counter->SampledCount = 0;
  }
  return ResetTime;
}

void TCounter::Sample() {
  SampleTime = time(0);
  for (TCounter *counter = FirstCounter; counter; counter = counter->NextCounter) {
    counter->SampledCount += counter->UnsampledCount;
    counter->UnsampledCount = 0;
  }
}

TCounter *TCounter::FirstCounter = 0;

time_t TCounter::SampleTime = time(0), TCounter::ResetTime = SampleTime;

