////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class ColorProfileUI : public UIEditor {
        YQ_OBJECT_DECLARE(ColorProfileUI, UIEditor)
    public:
        ColorProfileUI(UIFlags flags={});
        ColorProfileUI(const ColorProfileUI&);
        
        virtual ColorProfileUI* clone() const;
        
        void    color_profile();
        
        static void init_meta();
    };
}
