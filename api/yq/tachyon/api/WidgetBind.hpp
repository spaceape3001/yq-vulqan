////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class Widget;

    //! Utiltity to bind a viewer to the whatever...
    class WidgetBind {
    public:
        Widget*    widget() const { return m_widget; }
        
    protected:
        WidgetBind(Widget* v) : m_widget(v) {}
        virtual ~WidgetBind() {}
        
        Widget* const m_widget;
    };
}
