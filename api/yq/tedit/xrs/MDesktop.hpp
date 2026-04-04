////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MDesktop : public MTachyon {
        YQ_TACHYON_DECLARE(MDesktop, MTachyon)
        Q_OBJECT
    public:
    
        MDesktop(TypedID);
        ~MDesktop();
        
        static void init_meta();
    };
}
