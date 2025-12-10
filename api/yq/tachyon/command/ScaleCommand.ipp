////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ScaleCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ScaleCommand)

namespace yq::tachyon {

    ScaleCommand::ScaleCommand(const Header&h) : Command(h)
    {
    }

    ScaleCommand::ScaleCommand(const ScaleCommand& cp, const Header& h) : Command(cp, h)
    {
    }
    
    ScaleCommand::~ScaleCommand()
    {
    }

    PostCPtr    ScaleCommand::clone(rebind_k, const Header&h) const 
    {
        return new ScaleCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ScaleCommand::init_meta()
    {
        auto w = writer<ScaleCommand>();
        w.description("Scale Command");
    }
}
