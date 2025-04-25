////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/PositionCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PositionCommand)

namespace yq::tachyon {

    PositionCommand::PositionCommand(const Header&h) : SpatialCommand(h)
    {
    }

    PositionCommand::PositionCommand(const PositionCommand& cp, const Header& h) : SpatialCommand(cp, h)
    {
    }
    
    PositionCommand::~PositionCommand()
    {
    }

    PostCPtr    PositionCommand::clone(rebind_k, const Header&h) const 
    {
        return new PositionCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void PositionCommand::init_info()
    {
        auto w = writer<PositionCommand>();
        w.description("Position Command");
    }
}
