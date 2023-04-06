////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget3.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Widget3)

namespace yq {
    namespace tachyon {
        Widget3Info::Widget3Info(std::string_view zName, const WidgetInfo& base, const std::source_location& sl) :
            WidgetInfo(zName, base, sl)
        {
            set_option(WIDGET);
        }

        Widget3::Widget3()
        {
        }
        
        Widget3::~Widget3()
        {
            for(Widget3* w : m_children)
                delete w;
            m_children.clear();
        }

        void    Widget3::imgui_(ViContext& u)
        {
            for(Widget3* w : m_children)
                w->imgui_(u);
        }
        
        void    Widget3::vulkan_(ViContext& u)
        {
            for(Widget3* w : m_children)
                w->vulkan_(u);
        }
    }
}
