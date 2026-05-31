////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Scale²DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Scale²DUI, UIEditor)
    public:
        Scale²DUI(UIFlags flags={});
        Scale²DUI(const Scale²DUI&);
        
        virtual Scale²DUI* clone() const;
        
        void    scale();
        
        static void init_meta();
    };
}
