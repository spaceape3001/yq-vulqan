////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Widget2.hpp"
#include "Widget2InfoWriter.hpp"

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

    void Widget²::snap(Widget²Snap& sn) const
    {
        Widget::snap(sn);
        sn.bounds   = m_bounds;
    }

    void Widget²::init_info()
    {   
        auto w = writer<Widget²>();
        w.description("Abstract 2D widget");
    }
}
