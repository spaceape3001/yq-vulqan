////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CursorEnter.hpp"

#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorEnter)

namespace yq::tachyon {
    CursorEnter::CursorEnter(const Param&p) : CursorEvent(p)
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
