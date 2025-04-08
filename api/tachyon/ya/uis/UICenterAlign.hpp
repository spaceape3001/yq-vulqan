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
    
        UICenterAlign(UIFlags flags={});
        UICenterAlign(const UICenterAlign&);
        ~UICenterAlign();
        
        
    protected:
        using UIElements::render;
        void            render() override;
        UICenterAlign*  clone() const;
        
    private:
        float  m_width = -1;
    };
}
