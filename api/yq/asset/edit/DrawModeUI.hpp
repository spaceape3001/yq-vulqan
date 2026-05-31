////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class DrawModeUI : public UIEditor {
        YQ_OBJECT_DECLARE(DrawModeUI, UIEditor)
    public:
        DrawModeUI(UIFlags flags={});
        DrawModeUI(const DrawModeUI&);
        
        virtual DrawModeUI* clone() const;
        
        void    draw_mode();
        
        static void init_meta();
    };
}
