////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MManager : public MTachyon {
        YQ_TACHYON_DECLARE(MManager, MTachyon)
        Q_OBJECT
    public:
    
        MManager(TypedID);
        ~MManager();
        
        static void init_meta();
    };
}
