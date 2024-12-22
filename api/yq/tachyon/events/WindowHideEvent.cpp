////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowHideEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowHideEvent)

namespace yq::tachyon {

    WindowHideEvent::WindowHideEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowHideEvent::~WindowHideEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowHideEvent::init_info()
    {
        auto w = writer<WindowHideEvent>();
        w.description("Window Hide Event");
    }
}
