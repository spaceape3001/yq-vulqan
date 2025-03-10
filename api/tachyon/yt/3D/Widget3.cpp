////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Widget3.hpp"
#include "Widget3InfoWriter.hpp"

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

    void Widget³::init_info()
    {   
        auto w = writer<Widget³>();
        w.description("Abstract 3D widget");
    }
}
