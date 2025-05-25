////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIAppMain;
    class Widget;
    class WidgetInfo;
    class UIWindowWriter;
    
    /*! \brief Writer for the main application
    */
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
        UIToolBarWriter   toolbar(Cardinal, std::string_view kName);
        UIToolBarWriter   toolbar(const Vector2F&, std::string_view kName);
        UIWindowWriter      window(std::string_view kName={});

    private:
        static UIAppMain*   attach(Widget*);
        static UIAppMain*   attach(WidgetInfo*);
    };
}
