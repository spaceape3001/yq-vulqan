////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElements.hpp>

namespace yq::tachyon {
    class UIRightAlignWriter;
    
    class UIRightAlign : public UIElements {
        YQ_OBJECT_DECLARE(UIRightAlign, UIElements)
    public:
    
        using Writer = UIRightAlignWriter;
    
        static void init_meta();
    
        UIRightAlign(UIFlags flags={});
        UIRightAlign(const UIRightAlign&);
        ~UIRightAlign();
        
        UIRightAlign* clone() const;
        
    protected:
        using UIElements::render;
        void        render();
        
    private:
        float  m_width = -1;
    };
}
