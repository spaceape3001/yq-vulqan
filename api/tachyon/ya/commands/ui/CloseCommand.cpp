////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ui/CloseCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CloseCommand)

namespace yq::tachyon {

    CloseCommand::CloseCommand(const Header&h) : UICommand(h)
    {
    }

    CloseCommand::CloseCommand(const CloseCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    CloseCommand::~CloseCommand()
    {
    }

    PostCPtr    CloseCommand::clone(rebind_k, const Header&h) const 
    {
        return new CloseCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CloseCommand::init_info()
    {
        auto w = writer<CloseCommand>();
        w.description("Close Command");
    }
}
