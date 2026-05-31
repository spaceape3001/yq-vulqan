////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Scale³DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Scale³DUI, UIEditor)
    public:
        Scale³DUI(UIFlags flags={});
        Scale³DUI(const Scale³DUI&);
        
        virtual Scale³DUI* clone() const;
        
        void    scale();
        
        static void init_meta();
    };
}
