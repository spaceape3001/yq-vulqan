////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ui/IconifyCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::IconifyCommand)

namespace yq::tachyon {

    IconifyCommand::IconifyCommand(const Header&h) : UICommand(h)
    {
    }

    IconifyCommand::IconifyCommand(const IconifyCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    IconifyCommand::~IconifyCommand()
    {
    }

    PostCPtr    IconifyCommand::clone(rebind_k, const Header&h) const 
    {
        return new IconifyCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void IconifyCommand::init_info()
    {
        auto w = writer<IconifyCommand>();
        w.description("Iconify Command");
    }
}
