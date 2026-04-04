////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MKinetic : public MTachyon {
        YQ_TACHYON_DECLARE(MKinetic, MTachyon)
        Q_OBJECT
    public:
    
        MKinetic(TypedID);
        ~MKinetic();
        
        static void init_meta();
    };
}
