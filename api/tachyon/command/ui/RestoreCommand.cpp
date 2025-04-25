////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ui/RestoreCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RestoreCommand)

namespace yq::tachyon {

    RestoreCommand::RestoreCommand(const Header&h) : UICommand(h)
    {
    }

    RestoreCommand::RestoreCommand(const RestoreCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    RestoreCommand::~RestoreCommand()
    {
    }

    PostCPtr    RestoreCommand::clone(rebind_k, const Header&h) const 
    {
        return new RestoreCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void RestoreCommand::init_info()
    {
        auto w = writer<RestoreCommand>();
        w.description("Restore Command");
    }
}
