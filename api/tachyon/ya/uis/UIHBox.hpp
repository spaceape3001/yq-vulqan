////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>

namespace yq::tachyon {

    //! A line of non-wrapping UI elements
    class UIHBox : public UIElements {
    public:
        UIHBox(UIFlags flags={});
        UIHBox(const UIHBox&);
        ~UIHBox();
        
        UIHBox*     clone() const;
        
    };
}
