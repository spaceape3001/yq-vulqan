////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MPhysics.hpp>

namespace yq::tachyon {

    // 3 because Qt Moc is stupid on identifiers
    class MForce3 : public MPhysics {
        YQ_TACHYON_DECLARE(MForce3, MPhysics)
        Q_OBJECT
    public:
    
        MForce3(TypedID);
        ~MForce3();
        
        static void init_meta();
    };
}
