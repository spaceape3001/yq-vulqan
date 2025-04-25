////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/cursor/CursorNormalCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorNormalCommand)

namespace yq::tachyon {

    CursorNormalCommand::CursorNormalCommand(const Header&h) : CursorCommand(h)
    {
    }
    
    CursorNormalCommand::CursorNormalCommand(const CursorNormalCommand& cp, const Header&h) : CursorCommand(cp, h)
    {
    }

    CursorNormalCommand::~CursorNormalCommand()
    {
    }
    
    PostCPtr    CursorNormalCommand::clone(rebind_k, const Header&h) const
    {
        return new CursorNormalCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void CursorNormalCommand::init_info()
    {
        auto w = writer<CursorNormalCommand>();
        w.description("Cursor Normal Command");
    }
}
