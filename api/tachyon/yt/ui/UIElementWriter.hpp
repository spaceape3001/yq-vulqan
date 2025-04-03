////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>

namespace yq::tachyon {
    class WidgetInfo;
    class Widget;
    class UIElement;
    class UIItems;
    
    class UIElementWriter {
    public:
    
        UIElementWriter(Widget&);
        UIElementWriter(WidgetInfo&);
        UIElementWriter(UIItems&);
        ~UIElementWriter();
        
        UIElementWriter(const UIElementWriter&);
        UIElementWriter(UIElementWriter&&);
        UIElementWriter& operator=(const UIElementWriter&);
        UIElementWriter& operator=(UIElementWriter&&);

    protected:
        void        add(UIElement*);

    private:
        std::variant<std::monostate, UIItems*, Widget*, WidgetInfo*>     m_owner;
    };
}
