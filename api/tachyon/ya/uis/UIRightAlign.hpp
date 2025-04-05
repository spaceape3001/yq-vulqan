////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIItems.hpp>

namespace yq::tachyon {
    class UIRightAlign : public UIItems {
    public:
    
        UIRightAlign();
        UIRightAlign(const UIRightAlign&);
        ~UIRightAlign();
        
        UIRightAlign* clone() const;
        
    protected:
        using UIItems::render;
        void        render();
        
    private:
        float  m_width = -1;
    };
}
