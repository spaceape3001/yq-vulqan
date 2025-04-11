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

        using UIElementsWriter::menubar;
        UIMenuBarWriter         menubar(main_k);
        
        UIWindowWriter    window(std::string_view kName={});

    private:
        static UIAppMain*   attach(Widget*);
        static UIAppMain*   attach(WidgetInfo*);
    };
}
