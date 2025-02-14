////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/CursorCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorCommand)

namespace yq::tachyon {
    CursorCommand::CursorCommand(const Header& h) : Command(h)
    {
    }
    
    CursorCommand::CursorCommand(const CursorCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    CursorCommand::~CursorCommand()
    {
    }
    
    void CursorCommand::init_info()
    {
        auto w = writer<CursorCommand>();
        w.abstract();
        w.description("Cursor Command");
    }
}
