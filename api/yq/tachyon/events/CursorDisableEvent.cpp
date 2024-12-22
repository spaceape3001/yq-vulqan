////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CursorDisableEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorDisableEvent)

namespace yq::tachyon {

    CursorDisableEvent::CursorDisableEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    CursorDisableEvent::~CursorDisableEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CursorDisableEvent::init_info()
    {
        auto w = writer<CursorDisableEvent>();
        w.description("ursor Disable Event");
    }
}
