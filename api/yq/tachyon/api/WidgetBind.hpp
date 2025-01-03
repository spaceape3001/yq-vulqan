////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/widget.hpp>

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
