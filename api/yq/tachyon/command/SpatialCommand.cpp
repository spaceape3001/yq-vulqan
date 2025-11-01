////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/SpatialCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SpatialCommand)

namespace yq::tachyon {
    SpatialCommand::SpatialCommand(const Header& h) : Command(h)
    {
    }
    
    SpatialCommand::SpatialCommand(const SpatialCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    SpatialCommand::~SpatialCommand()
    {
    }
    
    void SpatialCommand::init_meta()
    {
        auto w = writer<SpatialCommand>();
        w.abstract();
        w.description("Spatial Command");
    }
}
