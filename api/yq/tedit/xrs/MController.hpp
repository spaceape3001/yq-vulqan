////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MController : public MTachyon {
        YQ_TACHYON_DECLARE(MController, MTachyon)
        Q_OBJECT
    public:
    
        MController(TypedID);
        ~MController();
        
        static void init_meta();
    };
}
