////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Widget.hpp"
#include "WidgetInfoWriter.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Viewer.hpp>
#include <yq/tachyon/api/WidgetBind.hpp>
#include <yq/tachyon/api/WidgetData.hpp>
#include <yq/tachyon/commands/ViewerShowCommand.hpp>
#include <yq/tachyon/commands/WidgetStartupCommand.hpp>

#include <yq/text/format.hpp>
#include <yq/meta/Init.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Widget)

namespace yq::tachyon {
    WidgetBind::WidgetBind(const Widget* v) : m_widget(v ? v->id() : WidgetID{}) 
    {
    }

    void Widget::init_info()
    {
        auto w = writer<Widget>();
        w.description("Widget base class");
        w.slot(&Widget::on_startup_command);
    }

    WidgetInfo::WidgetInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
        set(Flag::WIDGET);
        set(Type::Widget);
    }

    Widget::Widget(const Param& p) : Tachyon(p)
    {
        m_windowID      = std::string(fmt_hex(id()));
    }
    
    Widget::~Widget()
    {
        //for(Widget* w : m_children)
            //delete w;
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

    void    Widget::accept(close_t)
    {
        if(m_viewer)
            m_viewer -> accept(CLOSE);
    }
    

    bool    Widget::add_child(Widget* ch)
    {
        if(!ch)
            return false;
        return ch->set_parent(this);
    }

    PostAdvice    Widget::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const WidgetBind* p = dynamic_cast<const WidgetBind*>(&pp)){
            if(p->widget() != id())
                return REJECT;
        }
        return {};
    }

    bool    Widget::attached() const
    {
        return m_parent || m_viewer;
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

    bool    Widget::is_imgui() const
    {
        return metaInfo().is_imgui();
    }

    void    Widget::on_startup_command(const WidgetStartupCommand&)
    {
        startup();
    }
    
    void            Widget::prerecord(ViContext& u)
    {
        for(Widget* w : m_children)
            w->prerecord(u);
    }

    void    Widget::reject(close_t)
    {
        if(m_viewer)
            m_viewer -> reject(CLOSE);
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
            //m_parent->child_removed(this);
            std::erase(m_parent->m_children, this);
        }
        m_parent    = p;
        if(m_parent){
            m_parent->m_children.push_back(this);
            //m_parent->child_added(this);
        }
        return true;
   }

    void            Widget::startup()
    {
        send(new ViewerShowCommand(m_viewer), MG::Viewer);
    }

    Execution       Widget::tick(Context&) 
    {
        return {};
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
    
    Widget* Widget::widget_at(const Vector2D&) const
    {
        return const_cast<Widget*>(this);
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  EVENT PROCESSING (BELOW, one "section" per event type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

