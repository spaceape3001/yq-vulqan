////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MSpatial.hpp>

namespace yq::tachyon {

    // 3 because Qt Moc is stupid on identifiers
    class MSpatial3 : public MSpatial {
        YQ_TACHYON_DECLARE(MSpatial3, MSpatial)
        Q_OBJECT
    public:
    
        MSpatial3(TypedID);
        ~MSpatial3();
        
        static void init_meta();
    };
}
