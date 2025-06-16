////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/camera/CameraSetFOVCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraSetFOVCommand)

namespace yq::tachyon {
    
    CameraSetFOVCommand::CameraSetFOVCommand(const Header&h, unit::Degree f)
        : CameraCommand(h), m_fov(f)
    {
    }
    
    CameraSetFOVCommand::CameraSetFOVCommand(const CameraSetFOVCommand& cp, const Header&h)
        : CameraCommand(cp, h), m_fov(cp.m_fov)
    {
    }
    
    CameraSetFOVCommand::~CameraSetFOVCommand()
    {
    }
    
    PostCPtr    CameraSetFOVCommand::clone(rebind_k, const Header& h) const 
    {
        return new CameraSetFOVCommand(*this, h);
    }

    void CameraSetFOVCommand::init_info()
    {
        auto w = writer<CameraSetFOVCommand>();
        w.description("Sets a camera's Field of View");
        w.property("fov", &CameraSetFOVCommand::m_fov).tag({kTag_Save, kTag_Log});
    }
}
