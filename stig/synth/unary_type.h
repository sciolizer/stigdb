/* <stig/synth/unary_type.h> 

   TODO

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

#include <stig/synth/type.h>

namespace Stig {

  namespace Synth {

    /* TODO */
    class TUnaryType
        : public TType {
      NO_COPY_SEMANTICS(TUnaryType);
      public:

      /* TODO */
      typedef Type::TType (*TGet)(const Type::TType &);

      /* TODO */
      TUnaryType(TType *type, TGet get);

      /* TODO */
      virtual ~TUnaryType();

      /* TODO */
      virtual void ForEachRef(const std::function<void (TAnyRef &)> &cb);

      private:

      /* TODO */
      virtual Type::TType ComputeSymbolicType() const;

      /* TODO */
      TType *Type;

      /* TODO */
      TGet Get;

    };  // TType

  }  // Synth

}  // Stig

