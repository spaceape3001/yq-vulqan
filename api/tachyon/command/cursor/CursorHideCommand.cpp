////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/cursor/CursorHideCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorHideCommand)

namespace yq::tachyon {

    CursorHideCommand::CursorHideCommand(const Header&h) : CursorCommand(h)
    {
    }
    
    CursorHideCommand::CursorHideCommand(const CursorHideCommand& cp, const Header&h) : CursorCommand(cp, h)
    {
    }

    CursorHideCommand::~CursorHideCommand()
    {
    }
    
    PostCPtr    CursorHideCommand::clone(rebind_k, const Header&h) const
    {
        return new CursorHideCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void CursorHideCommand::init_info()
    {
        auto w = writer<CursorHideCommand>();
        w.description("Cursor Hide Command");
    }
}
