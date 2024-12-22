////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CursorNormalEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorNormalEvent)

namespace yq::tachyon {

    CursorNormalEvent::CursorNormalEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    CursorNormalEvent::~CursorNormalEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CursorNormalEvent::init_info()
    {
        auto w = writer<CursorNormalEvent>();
        w.description("Cursor Normal Event");
    }
}
