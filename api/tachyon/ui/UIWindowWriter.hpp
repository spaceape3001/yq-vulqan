////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElementsWriter.hpp>
#include <yq/typedef/size2.hpp>
#include <yq/typedef/vector2.hpp>

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
        // Element Data bits
        /////////////////////////////////////////////
        
        UIWindowWriter&     size(Size2F);
        UIWindowWriter&     width(float);
        UIWindowWriter&     height(float);
        
        UIWindowWriter&     position(Vector2F);
        UIWindowWriter&     x(float);
        UIWindowWriter&     y(float);
        
        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        UIMenuBarWriter     menubar();
        UIToolBarWriter   toolbar(Cardinal, std::string_view kName);
        UIToolBarWriter   toolbar(const Vector2F&, std::string_view kName);

    };
}
