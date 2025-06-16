////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/camera/CameraSetFarPlaneCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraSetFarPlaneCommand)

namespace yq::tachyon {
    
    CameraSetFarPlaneCommand::CameraSetFarPlaneCommand(const Header&h, double f)
        : CameraCommand(h), m_near(f)
    {
    }
    
    CameraSetFarPlaneCommand::CameraSetFarPlaneCommand(const CameraSetFarPlaneCommand& cp, const Header&h)
        : CameraCommand(cp, h), m_near(cp.m_near)
    {
    }
    
    CameraSetFarPlaneCommand::~CameraSetFarPlaneCommand()
    {
    }
    
    PostCPtr    CameraSetFarPlaneCommand::clone(rebind_k, const Header& h) const 
    {
        return new CameraSetFarPlaneCommand(*this, h);
    }

    void CameraSetFarPlaneCommand::init_info()
    {
        auto w = writer<CameraSetFarPlaneCommand>();
        w.description("Sets a camera's Far Plane");
        w.property("near", &CameraSetFarPlaneCommand::m_near).tag({kTag_Save, kTag_Log});
    }
}
