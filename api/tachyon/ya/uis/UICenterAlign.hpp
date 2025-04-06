////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>

namespace yq::tachyon {
    class UICenterAlign : public UIElements {
    public:
    
        UICenterAlign();
        UICenterAlign(const UICenterAlign&);
        ~UICenterAlign();
        
        UICenterAlign* clone() const;
        
    protected:
        using UIElements::render;
        void        render();
        
    private:
        float  m_width = -1;
    };
}
