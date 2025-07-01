////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/ui/FloatCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FloatCommand)

namespace yq::tachyon {

    FloatCommand::FloatCommand(const Header&h) : UICommand(h)
    {
    }

    FloatCommand::FloatCommand(const FloatCommand& cp, const Header& h) : UICommand(cp, h)
    {
    }
    
    FloatCommand::~FloatCommand()
    {
    }

    PostCPtr    FloatCommand::clone(rebind_k, const Header&h) const 
    {
        return new FloatCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void FloatCommand::init_info()
    {
        auto w = writer<FloatCommand>();
        w.description("Float Command");
    }
}
