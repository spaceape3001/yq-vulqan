////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CursorLeft.hpp"

#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorLeft)

namespace yq::tachyon {
    CursorLeft::CursorLeft(const Param& p) : CursorEvent(p)
    {
    }
    
    CursorLeft::~CursorLeft()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_cursor_left()
    {
        {
            auto w = writer<CursorLeft>();
            w.description("Cursor left a window/widget");
        }
    }
    
    YQ_INVOKE(reg_cursor_left();)
}
