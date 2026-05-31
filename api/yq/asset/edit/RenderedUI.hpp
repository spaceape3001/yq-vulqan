////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class RenderedUI : public UIEditor {
        YQ_OBJECT_DECLARE(RenderedUI, UIEditor)
    public:
        static void init_meta();
    
        RenderedUI(UIFlags flags={});
        RenderedUI(const RenderedUI&);
        ~RenderedUI();
        
        RenderedUI*  clone() const override;
        
        void    good();
        void    wireframe();
    };
}
