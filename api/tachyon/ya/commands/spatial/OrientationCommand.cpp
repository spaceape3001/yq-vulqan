////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/OrientationCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OrientationCommand)

namespace yq::tachyon {

    OrientationCommand::OrientationCommand(const Header&h) : SpatialCommand(h)
    {
    }

    OrientationCommand::OrientationCommand(const OrientationCommand& cp, const Header& h) : SpatialCommand(cp, h)
    {
    }
    
    OrientationCommand::~OrientationCommand()
    {
    }

    PostCPtr    OrientationCommand::clone(rebind_k, const Header&h) const 
    {
        return new OrientationCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void OrientationCommand::init_info()
    {
        auto w = writer<OrientationCommand>();
        w.description("Orientation Command");
    }
}
