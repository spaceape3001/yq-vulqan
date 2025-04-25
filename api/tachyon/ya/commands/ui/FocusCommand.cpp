////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/ui/FocusCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FocusCommand)

namespace yq::tachyon {

    FocusCommand::FocusCommand(const Header&h) : UICommand(h)
    {
    }

    FocusCommand::FocusCommand(const FocusCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    FocusCommand::~FocusCommand()
    {
    }

    PostCPtr    FocusCommand::clone(rebind_k, const Header&h) const 
    {
        return new FocusCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void FocusCommand::init_info()
    {
        auto w = writer<FocusCommand>();
        w.description("Focus Command");
    }
}
