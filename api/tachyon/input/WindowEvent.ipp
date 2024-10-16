////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowEvent.hpp"

#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>
#include <cassert>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowEvent)

namespace yq::tachyon {
    
    WindowEventInfo::WindowEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::WINDOW);
    }

    ////////////////////////////////////////////////////////////////////////////

    WindowEvent::WindowEvent(Window* w) : m_window(w)
    {
        assert(m_window);
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
