////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class ColorTriangle³UI : public UIEditor {
        YQ_OBJECT_DECLARE(ColorTriangle³UI, UIEditor)
    public:
        ColorTriangle³UI(UIFlags flags={});
        ColorTriangle³UI(const ColorTriangle³UI&);
        
        virtual ColorTriangle³UI* clone() const;
        
        static void init_info();
    };
}
