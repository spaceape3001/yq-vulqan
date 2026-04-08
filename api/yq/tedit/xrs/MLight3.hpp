////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MLight.hpp>

namespace yq::tachyon {

    // 3 because Qt Moc is stupid on identifiers
    class MLight3 : public MLight {
        YQ_TACHYON_DECLARE(MLight3, MLight)
        Q_OBJECT
    public:
    
        MLight3(TypedID);
        ~MLight3();
        
        static void init_meta();
    };
}
