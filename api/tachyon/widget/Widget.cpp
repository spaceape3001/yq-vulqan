////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Widget.hpp"
#include <yq/core/DelayInit.hpp>
#include <yq/text/format.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Widget)

namespace yq::tachyon {
    WidgetInfo::WidgetInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::WIDGET);
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

    void            Widget::prerecord(ViContext& u)
    {
        for(Widget* w : m_children)
            w->prerecord(u);
    }

    Widget*         Widget::root()
    {
        Widget* w   = this;
        while(w->m_parent)
            w   = w->m_parent;
        return w;
    }
    
    const Widget*   Widget::root() const
    {
        return const_cast<Widget*>(this) -> root();
    }

    bool    Widget::set_parent(Widget* p)
    {
        if(p == m_parent)   // already the parent
            return true;
        if(p == this)       // it's this widget
            return false;
        if(p && p->has_parentage(this))      // no loops please
            return false;
            
        if(m_parent){
            m_parent->child_removed(this);
            std::erase(m_parent->m_children, this);
        }
        m_parent    = p;
        if(m_parent){
            m_parent->m_children.push_back(this);
            m_parent->child_added(this);
        }
        return true;
   }

    Viewer*         Widget::viewer()
    {
        Widget* w   = root();
        if(w)
            return w->m_viewer;
        return nullptr;
    }
    
    const Viewer*   Widget::viewer() const 
    {
        return const_cast<Widget*>(this)->viewer();
    }
    
    static void reg_widget()
    {
        {
            auto w = writer<Widget>();
            w.description("Widget base class");
        }
    }
    
    YQ_INVOKE(reg_widget();)
}

