////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ui/UnfloatCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UnfloatCommand)

namespace yq::tachyon {

    UnfloatCommand::UnfloatCommand(const Header&h) : UICommand(h)
    {
    }

    UnfloatCommand::UnfloatCommand(const UnfloatCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    UnfloatCommand::~UnfloatCommand()
    {
    }

    PostCPtr    UnfloatCommand::clone(rebind_k, const Header&h) const 
    {
        return new UnfloatCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void UnfloatCommand::init_info()
    {
        auto w = writer<UnfloatCommand>();
        w.description("Unfloat Command");
    }
}
