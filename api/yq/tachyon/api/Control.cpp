////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Control.hpp>
#include <tachyon/api/ControlMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Control)

namespace yq::tachyon {
    ControlMeta::ControlMeta(std::string_view n, WidgetMeta& base, const std::source_location& sl) : WidgetMeta(n, base, sl)
    {
    }

    Control::Control()
    {
    }
    
    Control::~Control()
    {
    }
    
    void Control::init_meta()
    {
        auto w = writer<Control>();
        w.description("Control base");
    }
}
