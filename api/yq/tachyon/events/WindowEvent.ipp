////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowEvent.hpp"

#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowEvent)

namespace yq::tachyon {
    WindowEventInfo::WindowEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    WindowEvent::WindowEvent(ViewerID v, const Param& p) : Event(p), ViewerBind(v)
    {
    }
    
    WindowEvent::WindowEvent(const Viewer* v, const Param& p) : Event(p), ViewerBind(v)
    {
    }
    
    WindowEvent::~WindowEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowEvent::init_info()
    {
        auto w = writer<WindowEvent>();
        w.description("Window event base class");
    }
}
