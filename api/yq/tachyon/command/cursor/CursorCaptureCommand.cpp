////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/cursor/CursorCaptureCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorCaptureCommand)

namespace yq::tachyon {

    CursorCaptureCommand::CursorCaptureCommand(const Header&h) : CursorCommand(h)
    {
    }
    
    CursorCaptureCommand::CursorCaptureCommand(const CursorCaptureCommand& cp, const Header&h) : CursorCommand(cp, h)
    {
    }

    CursorCaptureCommand::~CursorCaptureCommand()
    {
    }
    
    PostCPtr    CursorCaptureCommand::clone(rebind_k, const Header&h) const
    {
        return new CursorCaptureCommand(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void CursorCaptureCommand::init_meta()
    {
        auto w = writer<CursorCaptureCommand>();
        w.description("Cursor Capture Command");
    }
}
