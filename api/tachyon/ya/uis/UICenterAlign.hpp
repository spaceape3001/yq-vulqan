////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIItems.hpp>

namespace yq::tachyon {
    class UICenterAlign : public UIItems {
    public:
    
        UICenterAlign();
        UICenterAlign(const UICenterAlign&);
        ~UICenterAlign();
        
        UICenterAlign* clone() const;
        
    protected:
        using UIItems::render;
        void        render();
        
    private:
        float  m_width = -1;
    };
}
