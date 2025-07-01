////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElements.hpp>

namespace yq::tachyon {

    class UIHLineWriter;

    //! A line of non-wrapping UI elements
    class UIHLine : public UIElements {
        YQ_OBJECT_DECLARE(UIHLine, UIElements)
    public:
    
        using Writer = UIHLineWriter;
        
        UIHLine(UIFlags flags={});
        UIHLine(const UIHLine&);
        ~UIHLine();
        
        UIHLine*     clone() const;
        
        static void init_meta();
    };
}
