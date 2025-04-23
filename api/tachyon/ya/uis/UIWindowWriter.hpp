////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElementsWriter.hpp>
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
        UIButtonBarWriter   buttonbar(UICardinal, std::string_view kName);
        UIButtonBarWriter   buttonbar(const Vector2F&, std::string_view kName);

    };
}
