////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/camera/SetNearPlaneCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetNearPlaneCommand)

namespace yq::tachyon {
    
    SetNearPlaneCommand::SetNearPlaneCommand(const Header&h, double f)
        : CameraCommand(h), m_near(f)
    {
    }
    
    SetNearPlaneCommand::SetNearPlaneCommand(const SetNearPlaneCommand& cp, const Header&h)
        : CameraCommand(cp, h), m_near(cp.m_near)
    {
    }
    
    SetNearPlaneCommand::~SetNearPlaneCommand()
    {
    }
    
    PostCPtr    SetNearPlaneCommand::clone(rebind_k, const Header& h) const 
    {
        return new SetNearPlaneCommand(*this, h);
    }

    void SetNearPlaneCommand::init_info()
    {
        auto w = writer<SetNearPlaneCommand>();
        w.description("Sets a camera's Near Plane");
        w.property("near", &SetNearPlaneCommand::m_near).tag({kTag_Save, kTag_Log});
    }
}
