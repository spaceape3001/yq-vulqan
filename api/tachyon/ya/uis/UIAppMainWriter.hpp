////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIAppMain;
    class Widget;
    class WidgetInfo;
    class UIWindowWriter;
    
    class UIAppMainWriter : public UIElementsWriter {
    public:
        UIAppMainWriter();
        UIAppMainWriter(UIAppMain*);
        UIAppMainWriter(Widget*);
        UIAppMainWriter(WidgetInfo*);
        UIAppMainWriter(const UIAppMainWriter&);
        ~UIAppMainWriter();
        
        UIAppMain*  element();
        
        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        UIMenuBarWriter     menubar();
        UIMenuBarWriter     menubar(main_k);
        UIButtonBarWriter     toolbar(UICardinal, std::string_view kName);
        UIButtonBarWriter     toolbar(const Vector2F&, std::string_view kName);
        UIWindowWriter      window(std::string_view kName={});

    private:
        static UIAppMain*   attach(Widget*);
        static UIAppMain*   attach(WidgetInfo*);
    };
}
