////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MKinetic.hpp>

namespace yq::tachyon {

    // 3 because Qt Moc is stupid on identifiers
    class MKinetic3 : public MKinetic {
        YQ_TACHYON_DECLARE(MKinetic3, MKinetic)
        Q_OBJECT
    public:
    
        MKinetic3(TypedID);
        ~MKinetic3();
        
        static void init_meta();
    };
}
