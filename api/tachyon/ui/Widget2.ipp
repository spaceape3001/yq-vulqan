////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget2.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Widget2)

namespace yq {
    namespace tachyon {
        Widget2Info::Widget2Info(std::string_view zName, const WidgetInfo& base, const std::source_location& sl) :
            WidgetInfo(zName, base, sl)
        {
        }

        Widget2::Widget2()
        {
        }
        
        Widget2::~Widget2()
        {
            for(Widget2* w : m_children)
                delete w;
            m_children.clear();
        }

        void    Widget2::imgui_(ViContext& u)
        {
            for(Widget2* w : m_children)
                w->imgui_(u);
        }
        
        void    Widget2::vulkan_(ViContext&u)
        {
            for(Widget2* w : m_children)
                w->vulkan_(u);
        }
    }
}
