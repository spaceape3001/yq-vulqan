////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/camera/CameraSetNearPlaneCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraSetNearPlaneCommand)

namespace yq::tachyon {
    
    CameraSetNearPlaneCommand::CameraSetNearPlaneCommand(const Header&h, double f)
        : CameraCommand(h), m_near(f)
    {
    }
    
    CameraSetNearPlaneCommand::CameraSetNearPlaneCommand(const CameraSetNearPlaneCommand& cp, const Header&h)
        : CameraCommand(cp, h), m_near(cp.m_near)
    {
    }
    
    CameraSetNearPlaneCommand::~CameraSetNearPlaneCommand()
    {
    }
    
    PostCPtr    CameraSetNearPlaneCommand::clone(rebind_k, const Header& h) const 
    {
        return new CameraSetNearPlaneCommand(*this, h);
    }

    void CameraSetNearPlaneCommand::init_info()
    {
        auto w = writer<CameraSetNearPlaneCommand>();
        w.description("Sets a camera's Near Plane");
        w.property("near", &CameraSetNearPlaneCommand::m_near).tag({kTag_Save, kTag_Log});
    }
}
