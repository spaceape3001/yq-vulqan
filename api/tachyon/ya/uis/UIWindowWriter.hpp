////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIWindow;
    
    class UIWindowWriter;
    
    class UIWindowWriter : public UIElementsWriter {
    public:

        UIWindowWriter();
        UIWindowWriter(UIWindow*);
        UIWindowWriter(const UIWindowWriter&);
        ~UIWindowWriter();
        
        UIWindow*           element();

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        UIMenuBarWriter     menubar();
        UIToolBarWriter     toolbar(UICardinal, std::string_view kName);
        UIToolBarWriter     toolbar(const Vector2F&, std::string_view kName);

    };
}
