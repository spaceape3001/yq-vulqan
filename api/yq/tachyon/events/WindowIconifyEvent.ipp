////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowIconifyEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowIconifyEvent)

namespace yq::tachyon {

    WindowIconifyEvent::WindowIconifyEvent(Viewer* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowIconifyEvent::~WindowIconifyEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowIconifyEvent::init_info()
    {
        auto w = writer<WindowIconifyEvent>();
        w.description("Window Iconify Event");
    }
}
