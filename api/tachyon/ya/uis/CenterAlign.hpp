////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIItems.hpp>

namespace yq::tachyon {
    class CenterAlign : public UIItems {
    public:
    
        CenterAlign();
        CenterAlign(const CenterAlign&);
        ~CenterAlign();
        
        CenterAlign* clone() const;
        
    protected:
        using UIItems::render;
        void        render();
        
    private:
        float  m_width = -1;
    };
}
