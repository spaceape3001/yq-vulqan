////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/CameraCommand.hpp>

#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraCommand)

namespace yq::tachyon {
    CameraCommand::CameraCommand(const Header&h) : Command(h)
    {
    }

    CameraCommand::CameraCommand(const CameraCommand& cp, const Header& h) : Command(cp, h)
    {
    }
    
    CameraCommand::~CameraCommand()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CameraCommand::init_meta()
    {
        auto w = writer<CameraCommand>();
        w.description("Camera command base class");
    }
}
