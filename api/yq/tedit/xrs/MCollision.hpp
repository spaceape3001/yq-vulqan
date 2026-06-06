////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MCollision : public MTachyon {
        YQ_TACHYON_DECLARE(MCollision, MTachyon)
        Q_OBJECT
    public:
    
        MCollision(TypedID);
        ~MCollision();
        
        static void init_meta();
    };
}
