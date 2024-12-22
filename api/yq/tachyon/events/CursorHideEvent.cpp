////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CursorHideEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorHideEvent)

namespace yq::tachyon {

    CursorHideEvent::CursorHideEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    CursorHideEvent::~CursorHideEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CursorHideEvent::init_info()
    {
        auto w = writer<CursorHideEvent>();
        w.description("Cursor Hide Event");
    }
}
