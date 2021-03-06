/* <stig/rpc/var/addr.h> 

   A variant addr.

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
#include <vector>

#include <stig/rpc/var.h>

namespace Stig {

  namespace Rpc {

    namespace Var {

      /* A variant addr. */
      class TAddr final
          : public TVar {
        public:

        /* A field is a sorting direction and a variant. */
        using TField = std::pair<TDir, const TVar *>;

        /* The type we use to contain our fields. */
        using TFields = std::vector<TField>;

        /* Start out with no fields. */
        TAddr() {}

        /* Destroys our fields, too. */
        virtual ~TAddr();

        /* Accept the visitor. */
        virtual void Accept(const TVisitor &visitor) const override;

        /* Add a field to the compound. */
        void AddField(TDir dir, TPtr &&var);

        /* The fields of the compound. */
        const TFields &GetFields() const {
          assert(this);
          return Fields;
        }

        private:

        /* See accessor. */
        TFields Fields;

      };  // TAddr

    }  // Var

  }  // Rpc

}  // Stig

