////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraPitchCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraPitchCommand)

namespace yq::tachyon {

    CameraPitchCommand::CameraPitchCommand(Camera* v, unit::Radian amt, const Param& p) : CameraCommand(v, p), m_angle(amt)
    {
    }
    
    CameraPitchCommand::~CameraPitchCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CameraPitchCommand::init_info()
    {
        auto w = writer<CameraPitchCommand>();
        w.description("Camera Pitch Command");
    }
}
