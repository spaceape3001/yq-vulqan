////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/cursor/CursorDisableCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorDisableCommand)

namespace yq::tachyon {

    CursorDisableCommand::CursorDisableCommand(const Header&h) : CursorCommand(h)
    {
    }
    
    CursorDisableCommand::CursorDisableCommand(const CursorDisableCommand& cp, const Header&h) : CursorCommand(cp, h)
    {
    }

    CursorDisableCommand::~CursorDisableCommand()
    {
    }
    
    PostCPtr    CursorDisableCommand::clone(rebind_k, const Header&h) const
    {
        return new CursorDisableCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void CursorDisableCommand::init_info()
    {
        auto w = writer<CursorDisableCommand>();
        w.description("Cursor Disable Command");
    }
}
