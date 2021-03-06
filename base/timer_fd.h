/* <base/timer_fd.h> 

   An wrapper around the Linux timerfd functions.

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

#pragma once

#include <cassert>
#include <cstdint>

#include <sys/timerfd.h>

#include <base/fd.h>
#include <base/no_copy_semantics.h>

namespace Base {

  /* TODO */
  class TTimerFd {
    NO_COPY_SEMANTICS(TTimerFd);
    public:

    /* TODO */
    TTimerFd(size_t milliseconds);

    /* TODO */
    const TFd &GetFd() const {
      assert(this);
      return Fd;
    }

    /* TODO */
    uint64_t Pop();

    private:

    /* TODO */
    TFd Fd;

  };  // TTimerFd

}  // Base

