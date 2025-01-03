////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/SpatialCommand.hpp>
//#include <yt/scene/Spatial.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SpatialCommand)

namespace yq::tachyon {
    SpatialCommand::SpatialCommand(TachyonID tid, const Param& p) : TachyonCommand(tid, p)
    {
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
