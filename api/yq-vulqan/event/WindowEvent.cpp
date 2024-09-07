////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowEvent.hpp"

#include <yq-toolbox/basic/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowEvent)

namespace yq::tachyon {
    
    WindowEventInfo::WindowEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
        set(Flag::WINDOW);
    }

    ////////////////////////////////////////////////////////////////////////////

    WindowEvent::WindowEvent()
    {
    }
    
    WindowEvent::~WindowEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_window_event()
    {
        {
            auto w = writer<WindowEvent>();
            w.description("WindowEvent base class");
        }
    }
    
    YQ_INVOKE(reg_window_event();)
}
