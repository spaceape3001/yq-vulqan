////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ui/MaximizeCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MaximizeCommand)

namespace yq::tachyon {

    MaximizeCommand::MaximizeCommand(const Header&h) : UICommand(h)
    {
    }

    MaximizeCommand::MaximizeCommand(const MaximizeCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    MaximizeCommand::~MaximizeCommand()
    {
    }

    PostCPtr    MaximizeCommand::clone(rebind_k, const Header&h) const 
    {
        return new MaximizeCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MaximizeCommand::init_info()
    {
        auto w = writer<MaximizeCommand>();
        w.description("Maximize Command");
    }
}
