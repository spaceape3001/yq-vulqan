////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/Stacked.hpp>

namespace yq::tachyon {
    Widget*         Stacked::active() 
    {
        if(m_active < m_children.size())
            return m_children[m_active];
        return nullptr;
    }
    
    const Widget*   Stacked::active() const
    {
        if(m_active < m_children.size())
            return m_children[m_active];
        return nullptr;
    }

    void            Stacked::set_active(size_t v)
    {
        m_active        = v;
    }
    
    void    Stacked::imgui_(ViContext&ctx) 
    {
        Widget*w    = active();
        if(w)
            w -> imgui_(ctx);
    }
    
    void    Stacked::vulkan_(ViContext&ctx) 
    {
        Widget*w    = active();
        if(w)
            w -> vulkan_(ctx);
    }

    Stacked::Stacked() = default;
    Stacked::~Stacked() = default;
}
YQ_OBJECT_IMPLEMENT(yq::tachyon::Stacked)
