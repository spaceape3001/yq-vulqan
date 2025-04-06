////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>

namespace yq::tachyon {
    class UIRightAlign : public UIElements {
    public:
    
        UIRightAlign();
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
