////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CursorEnter.hpp"

#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorEnter)

namespace yq::tachyon {
    CursorEnter::CursorEnter(Viewer* v, Widget*w, const Vector2D& cursor) : CursorEvent(v,w), m_cursor(cursor)
    {
    }
    
    CursorEnter::~CursorEnter()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_cursor_enter()
    {
        {
            auto w = writer<CursorEnter>();
            w.description("Cursor entered a window/widget");
        }
    }
    
    YQ_INVOKE(reg_cursor_enter();)
}
