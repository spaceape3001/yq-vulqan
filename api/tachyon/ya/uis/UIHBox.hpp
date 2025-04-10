////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>

namespace yq::tachyon {

    class UIHBoxWriter;

    //! A line of non-wrapping UI elements
    class UIHBox : public UIElements {
        YQ_OBJECT_DECLARE(UIHBox, UIElements)
    public:
    
        using Writer = UIHBoxWriter;
        
        UIHBox(UIFlags flags={});
        UIHBox(const UIHBox&);
        ~UIHBox();
        
        UIHBox*     clone() const;
        
        static void init_info();
    };
}
