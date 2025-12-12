////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OffsetCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OffsetCommand)

namespace yq::tachyon {

    OffsetCommand::OffsetCommand(const Header&h) : Command(h)
    {
    }

    OffsetCommand::OffsetCommand(const OffsetCommand& cp, const Header& h) : Command(cp, h)
    {
    }
    
    OffsetCommand::~OffsetCommand()
    {
    }

    PostCPtr    OffsetCommand::clone(rebind_k, const Header&h) const 
    {
        return new OffsetCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void OffsetCommand::init_meta()
    {
        auto w = writer<OffsetCommand>();
        w.description("Offset Command");
    }
}
