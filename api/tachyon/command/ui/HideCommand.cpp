////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ui/HideCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::HideCommand)

namespace yq::tachyon {

    HideCommand::HideCommand(const Header&h) : UICommand(h)
    {
    }

    HideCommand::HideCommand(const HideCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    HideCommand::~HideCommand()
    {
    }

    PostCPtr    HideCommand::clone(rebind_k, const Header&h) const 
    {
        return new HideCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void HideCommand::init_info()
    {
        auto w = writer<HideCommand>();
        w.description("Hide Command");
    }
}
