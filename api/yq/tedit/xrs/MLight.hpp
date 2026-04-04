////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MLight : public MTachyon {
        YQ_TACHYON_DECLARE(MLight, MTachyon)
        Q_OBJECT
    public:
    
        MLight(TypedID);
        ~MLight();
        
        static void init_meta();
    };
}
