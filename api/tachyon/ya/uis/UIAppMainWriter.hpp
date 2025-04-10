////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIAppMain;
    class Widget;
    class WidgetInfo;
    
    class UIAppMainWriter : public UIElementsWriter {
    public:
        UIAppMainWriter();
        UIAppMainWriter(UIAppMain*);
        UIAppMainWriter(Widget*);
        UIAppMainWriter(WidgetInfo*);
        UIAppMainWriter(const UIAppMainWriter&);
        ~UIAppMainWriter();
        
        UIAppMain*  element();
        
    protected:
        static UIAppMain*   attach(Widget*);
        static UIAppMain*   attach(WidgetInfo*);
    };
}
