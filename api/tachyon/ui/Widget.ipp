////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/Widget.hpp>
#include <basic/TextUtils.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Widget)

namespace yq::tachyon {
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

    void    Widget::imgui_(ViContext& u)
    {
        for(Widget* w : m_children)
            w->imgui_(u);
    }
    
    void    Widget::vulkan_(ViContext&u)
    {
        for(Widget* w : m_children)
            w->vulkan_(u);
    }

    bool    Widget::add_child(Widget* ch)
    {
        if(!ch)
            return false;
        return ch->set_parent(this);
    }

    bool    Widget::has_parentage(const Widget* p) const
    {
        if(!p)
            return false;
        for(const Widget* x = m_parent; x; x = x -> m_parent){
            if(p == x)
                return true;
        }
        return false;
    }

    bool    Widget::set_parent(Widget* p)
    {
        if(p == m_parent)   // already the parent
            return true;
        if(p == this)       // it's this widget
            return false;
        if(p && p->has_parentage(this))      // no loops please
            return false;
            
        if(m_parent)
            std::erase(m_parent->m_children, this);
        m_parent    = p;
        if(m_parent)
            m_parent->m_children.push_back(this);
        return true;
   }
}
