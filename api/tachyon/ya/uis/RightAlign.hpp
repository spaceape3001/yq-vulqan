////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIItems.hpp>

namespace yq::tachyon {
    class RightAlign : public UIItems {
    public:
    
        RightAlign();
        RightAlign(const RightAlign&);
        ~RightAlign();
        
        RightAlign* clone() const;
        
    protected:
        using UIItems::render;
        void        render();
        
    private:
        float  m_width = -1;
    };
}
