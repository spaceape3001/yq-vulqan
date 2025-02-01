////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/CameraCommand.hpp>

#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraCommand)

namespace yq::tachyon {
    CameraCommandInfo::CameraCommandInfo(std::string_view zName, CommandInfo& base, const std::source_location& sl) :
        CommandInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    CameraCommand::CameraCommand(const Header&h) : Command(h), CameraBind(CameraID())
    {
    }

    CameraCommand::CameraCommand(const Camera* v, const Header& h) : Command(h), CameraBind(v)
    {
        // DEPRECATED
    }
    
    CameraCommand::CameraCommand(CameraID v, const Header& h) : Command(h), CameraBind(v)
    {
        // DEPRECATED
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
