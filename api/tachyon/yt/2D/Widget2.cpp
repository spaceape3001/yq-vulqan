////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Widget2.hpp"
#include "Widget2InfoWriter.hpp"

#include <ya/commands/aabb/SetAABB2.hpp>
#include <ya/events/spatial/AABB2Event.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Widget²)

namespace yq::tachyon {
    Widget²Info::Widget²Info(std::string_view kName, WidgetInfo& pInfo, const std::source_location& sl) :
        WidgetInfo(kName, pInfo, sl)
    {
        set(Flag::D2);
        set(Type::Widget²);
    }

////////////////////////////////////////////////////////////////////////////////

    Widget²Data::~Widget²Data()
    {
    }

////////////////////////////////////////////////////////////////////////////////

    Widget²Snap::~Widget²Snap()
    {
    }

////////////////////////////////////////////////////////////////////////////////

    Widget²::Widget²()
    {
    }
    
    Widget²::~Widget²()
    {
    }

    void Widget²::on_set_aabb(const SetAABB²&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(cmd.aabb() == m_aabb)
            return ;
            
        m_aabb    = cmd.aabb();
        send(new AABB²Event({.source=*this}, m_aabb));
        aabb_changed();
    }

    void Widget²::set_aabb(const AxBox2D& box)
    {
        mail(new SetAABB²({.source=*this, .target=*this}, box));
    }

    void Widget²::snap(Widget²Snap& sn) const
    {
        Widget::snap(sn);
        sn.aabb   = m_aabb;
    }

    void Widget²::init_info()
    {   
        auto w = writer<Widget²>();
        w.description("Abstract 2D widget");
        w.property("aabb", &Widget²::m_aabb);
        w.slot(&Widget²::on_set_aabb);
    }
}
