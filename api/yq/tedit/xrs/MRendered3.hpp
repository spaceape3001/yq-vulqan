////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MRendered.hpp>

namespace yq::tachyon {

    // 3 because Qt Moc is stupid on identifiers
    class MRendered3 : public MRendered {
        YQ_TACHYON_DECLARE(MRendered3, MRendered)
        Q_OBJECT
    public:
    
        MRendered3(TypedID);
        ~MRendered3();
        
        static void init_meta();
    };
}
