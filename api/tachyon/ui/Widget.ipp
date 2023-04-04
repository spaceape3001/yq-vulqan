////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget.hpp>
#include <basic/TextUtils.hpp>
#include <atomic>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Widget)

namespace yq {
    namespace tachyon {
        WidgetInfo::WidgetInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
            ObjectInfo(zName, base, sl)
        {
            set_option(WIDGET);
        }

        Widget::Widget()
        {
            m_windowID      = std::string(fmt_hex(id()));
        }
        
        Widget::~Widget()
        {
            for(Widget* w : m_children)
                delete w;
            m_children.clear();
        }

        void    Widget::draw(/*UiData& uid*/)
        {
            for(auto& w : m_children)
                w->draw(/*uid*/);
        }
    }
}
