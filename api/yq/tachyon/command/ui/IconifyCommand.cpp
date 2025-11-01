////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/ui/IconifyCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

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

    void IconifyCommand::init_meta()
    {
        auto w = writer<IconifyCommand>();
        w.description("Iconify Command");
    }
}
