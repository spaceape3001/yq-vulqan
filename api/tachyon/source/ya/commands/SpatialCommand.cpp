////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/SpatialCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SpatialCommand)

namespace yq::tachyon {
    SpatialCommand::SpatialCommand(const Header& h) : Command(h)
    {
    }
    
    SpatialCommand::SpatialCommand(const SpatialCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    SpatialCommand::SpatialCommand(TachyonID, const Param&) : Command(Header{})
    {
        // DEPRECATED
    }

    SpatialCommand::~SpatialCommand()
    {
    }
    
    void SpatialCommand::init_info()
    {
        auto w = writer<SpatialCommand>();
        w.abstract();
        w.description("Spatial Command");
    }
}
