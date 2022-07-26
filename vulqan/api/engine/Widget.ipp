////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Widget.hpp"
#include <basic/TextUtils.hpp>
#include <atomic>

YQ_OBJECT_IMPLEMENT(yq::engine::Widget)

namespace yq {
    namespace engine {
        WidgetInfo::WidgetInfo(std::string_view zName, const MetaObjectInfo& base, const std::source_location& sl) :
            MetaObjectInfo(zName, base, sl)
        {
            set_option(WIDGET);
        }

        Widget::Widget()
        {
            static std::atomic<uint64_t>    s_next{1};
            m_widgetId  = "__widget__";
            m_widgetId += to_string_view((uint64_t) ++s_next);
        }
        
        Widget::~Widget()
        {
            m_children.clear();
        }

        void    Widget::draw(/*UiData& uid*/)
        {
            for(auto& w : m_children)
                w->draw(/*uid*/);
        }
    }
}
