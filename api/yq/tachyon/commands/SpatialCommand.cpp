////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SpatialCommand.hpp"
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/CommandInfoWriter.hpp>

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
