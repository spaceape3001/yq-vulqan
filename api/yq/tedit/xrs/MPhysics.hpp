////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MPhysics : public MTachyon {
        YQ_TACHYON_DECLARE(MPhysics, MTachyon)
        Q_OBJECT
    public:
    
        MPhysics(TypedID);
        ~MPhysics();
        
        static void init_meta();
    };
}
