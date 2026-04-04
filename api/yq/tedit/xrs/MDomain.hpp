////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MDomain : public MTachyon {
        YQ_TACHYON_DECLARE(MDomain, MTachyon)
        Q_OBJECT
    public:
    
        MDomain(TypedID);
        ~MDomain();
        
        static void init_meta();
    };
}
