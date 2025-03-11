////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Widget4.hpp"
#include "Widget4InfoWriter.hpp"

YQ_TACHYON_IMPLEMENT(yq::tachyon::Widget⁴)

namespace yq::tachyon {
    Widget⁴Info::Widget⁴Info(std::string_view kName, WidgetInfo& pInfo, const std::source_location& sl) :
        WidgetInfo(kName, pInfo, sl)
    {
        set(Flag::D4);
        set(Type::Widget⁴);
    }

////////////////////////////////////////////////////////////////////////////////

    Widget⁴Data::~Widget⁴Data()
    {
    }

////////////////////////////////////////////////////////////////////////////////

    Widget⁴Snap::~Widget⁴Snap()
    {
    }

////////////////////////////////////////////////////////////////////////////////

    Widget⁴::Widget⁴()
    {
    }
    
    Widget⁴::~Widget⁴()
    {
    }

    void Widget⁴::snap(Widget⁴Snap& sn) const
    {
        Widget::snap(sn);
        sn.bounds   = m_bounds;
    }

    void Widget⁴::init_info()
    {   
        auto w = writer<Widget⁴>();
        w.description("Abstract 4D widget");
    }
}
