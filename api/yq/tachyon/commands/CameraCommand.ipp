////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraCommand.hpp"

#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraCommand)

namespace yq::tachyon {
    CameraCommandInfo::CameraCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    CameraCommand::CameraCommand(Camera* v, const Param& p) : Command(p), CameraBind(v)
    {
    }
    
    CameraCommand::CameraCommand(CameraID v, const Param& p) : Command(p), CameraBind(v)
    {
    }
    
    CameraCommand::~CameraCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CameraCommand::init_info()
    {
        auto w = writer<CameraCommand>();
        w.description("Camera command base class");
    }
}
