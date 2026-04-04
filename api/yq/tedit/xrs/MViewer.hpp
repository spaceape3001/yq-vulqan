////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MViewer : public MTachyon {
        YQ_TACHYON_DECLARE(MViewer, MTachyon)
        Q_OBJECT
    public:
    
        MViewer(TypedID);
        ~MViewer();
        
        static void init_meta();
    };
}
