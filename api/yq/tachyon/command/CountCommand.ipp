////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CountCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CountCommand)

namespace yq::tachyon {

    CountCommand::CountCommand(const Header&h) : Command(h)
    {
    }

    CountCommand::CountCommand(const CountCommand& cp, const Header& h) : Command(cp, h)
    {
    }
    
    CountCommand::~CountCommand()
    {
    }

    PostCPtr    CountCommand::clone(rebind_k, const Header&h) const 
    {
        return new CountCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CountCommand::init_meta()
    {
        auto w = writer<CountCommand>();
        w.description("Count Command");
    }
}
