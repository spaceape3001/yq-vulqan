////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Widget3.hpp"
#include "Widget3InfoWriter.hpp"

#include <ya/commands/aabb/SetAABB3.hpp>
#include <ya/events/spatial/AABB3Event.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Widget³)

namespace yq::tachyon {
    Widget³Info::Widget³Info(std::string_view kName, WidgetInfo& pInfo, const std::source_location& sl) :
        WidgetInfo(kName, pInfo, sl)
    {
        set(Flag::D3);
        set(Type::Widget³);
    }

////////////////////////////////////////////////////////////////////////////////

    Widget³Data::~Widget³Data()
    {
    }

////////////////////////////////////////////////////////////////////////////////

    Widget³Snap::~Widget³Snap()
    {
    }

////////////////////////////////////////////////////////////////////////////////

    Widget³::Widget³()
    {
    }
    
    Widget³::~Widget³()
    {
    }

    void Widget³::on_set_aabb(const SetAABB³&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(cmd.aabb() == m_aabb)
            return ;
            
        m_aabb    = cmd.aabb();
        send(new AABB³Event({.source=*this}, m_aabb));
        aabb_changed();
    }

    void Widget³::set_aabb(const AxBox3D& box)
    {
        mail(new SetAABB³({.source=*this, .target=*this}, box));
    }

    void Widget³::snap(Widget³Snap& sn) const
    {
        Widget::snap(sn);
        sn.aabb   = m_aabb;
    }

    void Widget³::init_info()
    {   
        auto w = writer<Widget³>();
        w.description("Abstract 3D widget");
        w.slot(&Widget³::on_set_aabb);
    }
}
