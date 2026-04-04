////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MGroup : public MTachyon {
        YQ_TACHYON_DECLARE(MGroup, MTachyon)
        Q_OBJECT
    public:
    
        MGroup(TypedID);
        ~MGroup();
        
        static void init_meta();
    };
}
