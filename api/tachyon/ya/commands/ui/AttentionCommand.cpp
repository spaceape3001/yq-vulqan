////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ui/AttentionCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AttentionCommand)

namespace yq::tachyon {

    AttentionCommand::AttentionCommand(const Header&h) : UICommand(h)
    {
    }

    AttentionCommand::AttentionCommand(const AttentionCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    AttentionCommand::~AttentionCommand()
    {
    }

    PostCPtr    AttentionCommand::clone(rebind_k, const Header&h) const 
    {
        return new AttentionCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AttentionCommand::init_info()
    {
        auto w = writer<AttentionCommand>();
        w.description("Attention Command");
    }
}
