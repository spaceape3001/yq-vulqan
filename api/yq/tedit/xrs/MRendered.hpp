////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MRendered : public MTachyon {
        YQ_TACHYON_DECLARE(MRendered, MTachyon)
        Q_OBJECT
    public:
    
        MRendered(TypedID);
        ~MRendered();
        
        static void init_meta();
    };
}
