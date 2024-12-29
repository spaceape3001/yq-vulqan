////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PositionCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PositionCommand)

namespace yq::tachyon {
    PositionCommand::PositionCommand(TachyonID tid, const Param& p) : TachyonCommand(tid, p)
    {
    }
    
    PositionCommand::~PositionCommand()
    {
    }
    
    void PositionCommand::init_info()
    {
        auto w = writer<PositionCommand>();
        w.abstract();
        w.description("Position Command");
    }
}
