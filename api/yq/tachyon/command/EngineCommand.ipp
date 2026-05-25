////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EngineCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::EngineCommand)

namespace yq::tachyon {
    EngineCommand::EngineCommand(const Header& h) : Command(h)
    {
    }
    
    EngineCommand::EngineCommand(const EngineCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    EngineCommand::~EngineCommand()
    {
    }
    
    void EngineCommand::init_meta()
    {
        auto w = writer<EngineCommand>();
        w.abstract();
        w.description("Engine Command");
    }
}
