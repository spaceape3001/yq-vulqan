////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class ScreenScaleMUI : public UIEditor {
        YQ_OBJECT_DECLARE(ScreenScaleMUI, UIEditor)
    public:
        ScreenScaleMUI(UIFlags flags={});
        ScreenScaleMUI(const ScreenScaleMUI&);
        
        virtual ScreenScaleMUI* clone() const;
        
        void    screen_scale();
        
        static void init_meta();
    };
}
