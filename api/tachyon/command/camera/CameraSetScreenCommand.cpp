////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/camera/CameraSetScreenCommand.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraSetScreenCommand)

namespace yq::tachyon {
    
    CameraSetScreenCommand::CameraSetScreenCommand(const Header&h, const Rectangle2D& r)
        : CameraCommand(h), m_screen(r)
    {
    }
    
    CameraSetScreenCommand::CameraSetScreenCommand(const CameraSetScreenCommand& cp, const Header&h)
        : CameraCommand(cp, h), m_screen(cp.m_screen)
    {
    }
    
    CameraSetScreenCommand::~CameraSetScreenCommand()
    {
    }
    
    PostCPtr    CameraSetScreenCommand::clone(rebind_k, const Header& h) const 
    {
        return new CameraSetScreenCommand(*this, h);
    }

    void CameraSetScreenCommand::init_info()
    {
        auto w = writer<CameraSetScreenCommand>();
        w.description("Sets a camera's screen rectangle");
        w.property("rectangle", &CameraSetScreenCommand::m_screen).tag(kTag_Save);
        w.property("x", &CameraSetScreenCommand::x).tag(kTag_Log);
        w.property("y", &CameraSetScreenCommand::y).tag(kTag_Log);
        w.property("w", &CameraSetScreenCommand::width).tag(kTag_Log);
        w.property("h", &CameraSetScreenCommand::height).tag(kTag_Log);
    }
}
