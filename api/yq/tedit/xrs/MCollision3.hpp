////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MCollision.hpp>

namespace yq::tachyon {

    // 3 because Qt Moc is stupid on identifiers
    class MCollision3 : public MCollision {
        YQ_TACHYON_DECLARE(MCollision3, MCollision)
        Q_OBJECT
    public:
    
        MCollision3(TypedID);
        ~MCollision3();
        
        static void init_meta();
    };
}
