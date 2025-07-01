////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/camera/SetFarPlaneCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetFarPlaneCommand)

namespace yq::tachyon {
    
    SetFarPlaneCommand::SetFarPlaneCommand(const Header&h, double f)
        : CameraCommand(h), m_far(f)
    {
    }
    
    SetFarPlaneCommand::SetFarPlaneCommand(const SetFarPlaneCommand& cp, const Header&h)
        : CameraCommand(cp, h), m_far(cp.m_far)
    {
    }
    
    SetFarPlaneCommand::~SetFarPlaneCommand()
    {
    }
    
    PostCPtr    SetFarPlaneCommand::clone(rebind_k, const Header& h) const 
    {
        return new SetFarPlaneCommand(*this, h);
    }

    void SetFarPlaneCommand::init_info()
    {
        auto w = writer<SetFarPlaneCommand>();
        w.description("Sets a camera's Far Plane");
        w.property("far", &SetFarPlaneCommand::m_far).tag({kTag_Save, kTag_Log});
    }
}
