////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "StackedWidget.hpp"

namespace yq::tachyon {
    Widget*         StackedWidget::active() 
    {
        if(m_active < m_children.size())
            return m_children[m_active];
        return nullptr;
    }
    
    const Widget*   StackedWidget::active() const
    {
        if(m_active < m_children.size())
            return m_children[m_active];
        return nullptr;
    }

    void            StackedWidget::set_active(size_t v)
    {
        m_active        = v;
    }
    
    void    StackedWidget::imgui_(ViContext&ctx) 
    {
        Widget*w    = active();
        if(w)
            w -> imgui_(ctx);
    }
    
    void    StackedWidget::vulkan_(ViContext&ctx) 
    {
        Widget*w    = active();
        if(w)
            w -> vulkan_(ctx);
    }

    StackedWidget::StackedWidget() = default;
    StackedWidget::~StackedWidget() = default;
}
YQ_OBJECT_IMPLEMENT(yq::tachyon::StackedWidget)
