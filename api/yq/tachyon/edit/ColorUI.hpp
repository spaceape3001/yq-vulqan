////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class ColorUI : public UIEditor {
        YQ_OBJECT_DECLARE(ColorUI, UIEditor)
    public:
        ColorUI(UIFlags flags={});
        ColorUI(const ColorUI&);
        
        virtual ColorUI* clone() const;
        
        void    color();
        
        static void init_meta();
    };
}
