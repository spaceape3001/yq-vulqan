////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Widget1.hpp"
#include "Widget1InfoWriter.hpp"

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

    void Widget¹::init_info()
    {   
        auto w = writer<Widget¹>();
        w.description("Abstract 1D widget");
    }
}
