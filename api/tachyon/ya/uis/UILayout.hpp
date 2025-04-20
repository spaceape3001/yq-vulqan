////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElement.hpp>

namespace yq::tachyon {
    class UILayoutWriter;
    
    /*! \brief Lays out the items within it
    
        \note We're *NOT* using UIElements base as we don't want to 
            impost restrictions
    */
    class UILayout : public UIElement {
        YQ_OBJECT_DECLARE(UILayout, UIElement)
    public:
    
        using Writer = UILayoutWriter;
    
        UILayout(UIFlags flags={});
        UILayout(const UILayout&);
        ~UILayout();
        static void init_info();
    };
}
