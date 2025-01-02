////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ID.hpp>
#include <yt/typedef/widget.hpp>

namespace yq::tachyon {
    class Widget;

    //! Utiltity to bind a viewer to the whatever...
    class WidgetBind {
    public:
        WidgetID    widget() const { return m_widget; }
        
    protected:
        WidgetBind(WidgetID v) : m_widget(v) {}
        WidgetBind(const Widget* v);
        virtual ~WidgetBind() {}
        
        WidgetID const m_widget;
    };
}
