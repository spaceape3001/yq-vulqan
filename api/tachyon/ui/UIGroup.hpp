////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElements.hpp>

namespace yq::tachyon {
    class UIGroupWriter;
    class UIGroup : public UIElements {
        YQ_OBJECT_DECLARE(UIGroup, UIElements)
    public:
    
        using Writer = UIGroupWriter;
        
        UIGroup(UIFlags flags={});
        UIGroup(const UIGroup&);
        ~UIGroup();
        
        UIGroup*     clone() const;

        virtual void    render() override;
        
        static void init_info();
    };
}
