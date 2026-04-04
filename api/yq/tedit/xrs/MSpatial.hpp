////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MSpatial : public MTachyon {
        YQ_TACHYON_DECLARE(MSpatial, MTachyon)
        Q_OBJECT
    public:
    
        MSpatial(TypedID);
        ~MSpatial();
        
        static void init_meta();
    };
}
