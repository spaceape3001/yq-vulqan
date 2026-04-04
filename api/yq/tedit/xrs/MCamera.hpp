////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MCamera : public MTachyon {
        YQ_TACHYON_DECLARE(MCamera, MTachyon)
        Q_OBJECT
    public:
    
        MCamera(TypedID);
        ~MCamera();
        
        static void init_meta();
    };
}
