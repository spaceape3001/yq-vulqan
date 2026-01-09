////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindow.hpp>
#include <yq/tachyon/ui/UIElementsWriter.hpp>
#include <yq/typedef/axside2.hpp>
#include <yq/typedef/size2.hpp>
#include <yq/typedef/vector2.hpp>

namespace yq::tachyon {
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
        
        UIWindowWriter&     bumper(left_k, float);
        UIWindowWriter&     bumper(top_k, float);
        UIWindowWriter&     bumper(right_k, float);
        UIWindowWriter&     bumper(bottom_k, float);
        UIWindowWriter&     bumpers(const AxSide2F&);
        
        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        //UIMenuBarWriter     menubar();
        //UIToolBarWriter   toolbar(Cardinal, std::string_view kName);
        //UIToolBarWriter   toolbar(const Vector2F&, std::string_view kName);

    };
}
