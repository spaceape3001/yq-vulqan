////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/spatial/OrientationCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

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

    void OrientationCommand::init_meta()
    {
        auto w = writer<OrientationCommand>();
        w.description("Orientation Command");
    }
}
