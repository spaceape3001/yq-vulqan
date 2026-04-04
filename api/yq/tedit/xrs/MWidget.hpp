////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MTachyon.hpp>

namespace yq::tachyon {
    class MWidget : public MTachyon {
        YQ_TACHYON_DECLARE(MWidget, MTachyon)
        Q_OBJECT
    public:
    
        MWidget(TypedID);
        ~MWidget();
        
        static void init_meta();
    };
}
