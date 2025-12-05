////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class LightUI : public UIEditor {
        YQ_OBJECT_DECLARE(LightUI, UIEditor)
    public:
        LightUI(UIFlags flags={});
        LightUI(const LightUI&);
        
        virtual LightUI* clone() const;
        
        void    color();
        void    intensity();
        
        static void init_meta();
    };
}
