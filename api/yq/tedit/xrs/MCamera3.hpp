////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MCamera.hpp>

namespace yq::tachyon {

    // 3 because Qt Moc is stupid on identifiers
    class MCamera3 : public MCamera {
        YQ_TACHYON_DECLARE(MCamera3, MCamera)
        Q_OBJECT
    public:
    
        MCamera3(TypedID);
        ~MCamera3();
        
        static void init_meta();
    };
}
