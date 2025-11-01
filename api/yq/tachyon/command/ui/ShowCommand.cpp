////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ui/ShowCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ShowCommand)

namespace yq::tachyon {

    ShowCommand::ShowCommand(const Header&h) : UICommand(h)
    {
    }

    ShowCommand::ShowCommand(const ShowCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    ShowCommand::~ShowCommand()
    {
    }

    PostCPtr    ShowCommand::clone(rebind_k, const Header&h) const 
    {
        return new ShowCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ShowCommand::init_meta()
    {
        auto w = writer<ShowCommand>();
        w.description("Show Command");
    }
}
