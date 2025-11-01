////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/camera/SetScreenCommand.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScreenCommand)

namespace yq::tachyon {
    
    SetScreenCommand::SetScreenCommand(const Header&h, const Rectangle2D& r)
        : CameraCommand(h), m_screen(r)
    {
    }
    
    SetScreenCommand::SetScreenCommand(const SetScreenCommand& cp, const Header&h)
        : CameraCommand(cp, h), m_screen(cp.m_screen)
    {
    }
    
    SetScreenCommand::~SetScreenCommand()
    {
    }
    
    PostCPtr    SetScreenCommand::clone(rebind_k, const Header& h) const 
    {
        return new SetScreenCommand(*this, h);
    }

    void SetScreenCommand::init_meta()
    {
        auto w = writer<SetScreenCommand>();
        w.description("Sets a camera's screen rectangle");
        w.property("rectangle", &SetScreenCommand::m_screen).tag(kTag_Save);
        w.property("x", &SetScreenCommand::x).tag(kTag_Log);
        w.property("y", &SetScreenCommand::y).tag(kTag_Log);
        w.property("w", &SetScreenCommand::width).tag(kTag_Log);
        w.property("h", &SetScreenCommand::height).tag(kTag_Log);
    }
}
