////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>

namespace yq::tachyon {
    class UICenterAlignWriter;
    
    class UICenterAlign : public UIElements {
        YQ_OBJECT_DECLARE(UICenterAlign, UIElements)
    public:
    
        using Writer = UICenterAlignWriter;
    
        UICenterAlign(UIFlags flags={});
        UICenterAlign(const UICenterAlign&);
        ~UICenterAlign();
        
        static void init_info();
        
    protected:
        using UIElements::render;
        void            render() override;
        UICenterAlign*  clone() const;
        
    private:
        float  m_width = -1;
    };
}
