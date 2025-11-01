////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/camera/SetFOVCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetFOVCommand)

namespace yq::tachyon {
    
    SetFOVCommand::SetFOVCommand(const Header&h, unit::Degree f)
        : CameraCommand(h), m_fov(f)
    {
    }
    
    SetFOVCommand::SetFOVCommand(const SetFOVCommand& cp, const Header&h)
        : CameraCommand(cp, h), m_fov(cp.m_fov)
    {
    }
    
    SetFOVCommand::~SetFOVCommand()
    {
    }
    
    PostCPtr    SetFOVCommand::clone(rebind_k, const Header& h) const 
    {
        return new SetFOVCommand(*this, h);
    }

    void SetFOVCommand::init_meta()
    {
        auto w = writer<SetFOVCommand>();
        w.description("Sets a camera's Field of View");
        w.property("fov", &SetFOVCommand::m_fov).tag({kTag_Save, kTag_Log});
    }
}
