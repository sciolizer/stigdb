/* <stig/sabot/state_dumper.h> 

   Dump a human-readable description of a sabot state.

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
#include <ostream>

#include <stig/sabot/state.h>

namespace Stig {

  namespace Sabot {

    /* Dump a human-readable description of a sabot state. */
    class TStateDumper final
        : public TStateVisitor {
      public:

      /* Caches a reference to the stream. */
      TStateDumper(std::ostream &strm)
          : Strm(strm) {
        assert(&strm);
      }

      /* Overrides. */
      virtual void operator()(const State::TFree &state) const override;
      virtual void operator()(const State::TTombstone &state) const override;
      virtual void operator()(const State::TVoid &state) const override;
      virtual void operator()(const State::TInt8 &state) const override;
      virtual void operator()(const State::TInt16 &state) const override;
      virtual void operator()(const State::TInt32 &state) const override;
      virtual void operator()(const State::TInt64 &state) const override;
      virtual void operator()(const State::TUInt8 &state) const override;
      virtual void operator()(const State::TUInt16 &state) const override;
      virtual void operator()(const State::TUInt32 &state) const override;
      virtual void operator()(const State::TUInt64 &state) const override;
      virtual void operator()(const State::TBool &state) const override;
      virtual void operator()(const State::TChar &state) const override;
      virtual void operator()(const State::TFloat &state) const override;
      virtual void operator()(const State::TDouble &state) const override;
      virtual void operator()(const State::TDuration &state) const override;
      virtual void operator()(const State::TTimePoint &state) const override;
      virtual void operator()(const State::TUuid &state) const override;
      virtual void operator()(const State::TBlob &state) const override;
      virtual void operator()(const State::TStr &state) const override;
      virtual void operator()(const State::TDesc &state) const override;
      virtual void operator()(const State::TOpt &state) const override;
      virtual void operator()(const State::TSet &state) const override;
      virtual void operator()(const State::TVector &state) const override;
      virtual void operator()(const State::TMap &state) const override;
      virtual void operator()(const State::TRecord &state) const override;
      virtual void operator()(const State::TTuple &state) const override;

      private:

      /* The stream to which we dump. */
      std::ostream &Strm;

      /* TODO */
      void OnArrayOfPairsOfStates(const char *name, const char *kwd_for_zero_size, const State::TArrayOfPairsOfStates &state) const;

      /* TODO */
      void OnArrayOfSingleStates(const char *name, const char *kwd_for_zero_size, const State::TArrayOfSingleStates &state) const;

      /* TODO */
      void OnContainerOfSingleStates(const char *name, const State::TArrayOfSingleStates &state) const;

    };  // TTypeDumper

  }  // Sabot

}  // Stig

