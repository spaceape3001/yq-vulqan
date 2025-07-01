////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Control.hpp>
#include <tachyon/api/ControlInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Control)

namespace yq::tachyon {
    ControlInfo::ControlInfo(std::string_view n, WidgetMeta& base, const std::source_location& sl) : WidgetMeta(n, base, sl)
    {
    }

    Control::Control()
    {
    }
    
    Control::~Control()
    {
    }
    
    void Control::init_info()
    {
        auto w = writer<Control>();
        w.description("Control base");
    }
}
