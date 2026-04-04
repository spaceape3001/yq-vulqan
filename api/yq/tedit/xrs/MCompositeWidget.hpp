////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tedit/xrs/MWidget.hpp>

namespace yq::tachyon {
    class MCompositeWidget : public MWidget {
        YQ_TACHYON_DECLARE(MCompositeWidget, MWidget)
        Q_OBJECT
    public:
    
        MCompositeWidget(TypedID);
        ~MCompositeWidget();
        
        static void init_meta();
    };
}
