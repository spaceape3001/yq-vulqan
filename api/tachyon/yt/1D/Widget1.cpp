////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Widget1.hpp"
#include "Widget1InfoWriter.hpp"

#include <ya/commands/aabb/SetAABB1.hpp>
#include <ya/events/spatial/AABB1Event.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Widget¹)

namespace yq::tachyon {
    Widget¹Info::Widget¹Info(std::string_view kName, WidgetInfo& pInfo, const std::source_location& sl) :
        WidgetInfo(kName, pInfo, sl)
    {
        set(Flag::D1);
        set(Type::Widget¹);
    }

////////////////////////////////////////////////////////////////////////////////

    Widget¹Data::~Widget¹Data()
    {
    }

////////////////////////////////////////////////////////////////////////////////

    Widget¹Snap::~Widget¹Snap()
    {
    }

////////////////////////////////////////////////////////////////////////////////

    Widget¹::Widget¹()
    {
    }
    
    Widget¹::~Widget¹()
    {
    }

    void Widget¹::on_set_aabb(const SetAABB¹&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(cmd.aabb() == m_aabb)
            return ;
            
        m_aabb    = cmd.aabb();
        send(new AABB¹Event({.source=*this}, m_aabb));
        aabb_changed();
    }

    void Widget¹::set_aabb(const AxBox1D& box)
    {
        mail(new SetAABB¹({.source=*this, .target=*this}, box));
    }

    void Widget¹::snap(Widget¹Snap& sn) const
    {
        Widget::snap(sn);
        sn.aabb   = m_aabb;
    }

    void Widget¹::init_info()
    {   
        auto w = writer<Widget¹>();
        w.description("Abstract 1D widget");
    }
}
