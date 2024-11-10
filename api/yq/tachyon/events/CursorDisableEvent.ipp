////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CursorDisableEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorDisableEvent)

namespace yq::tachyon {

    CursorDisableEvent::CursorDisableEvent(Viewer* v, const Param& p) : WindowEvent(v, p)
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
