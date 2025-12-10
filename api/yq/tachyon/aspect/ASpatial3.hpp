////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/APosition3.hpp>
#include <yq/tachyon/aspect/AOrientation3.hpp>
#include <yq/tachyon/aspect/AScale3.hpp>

namespace yq::tachyon {
    class ASpatial³ : public virtual Tachyon::Helper, public APosition³, public AOrientation³, public AScale³ {
    public:
    
    protected:
        ASpatial³();
        ~ASpatial³();

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
    };
}
