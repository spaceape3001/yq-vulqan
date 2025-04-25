////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SizeCommand)

namespace yq::tachyon {

    SizeCommand::SizeCommand(const Header&h) : SpatialCommand(h)
    {
    }

    SizeCommand::SizeCommand(const SizeCommand& cp, const Header& h) : SpatialCommand(cp, h)
    {
    }
    
    SizeCommand::~SizeCommand()
    {
    }

    PostCPtr    SizeCommand::clone(rebind_k, const Header&h) const 
    {
        return new SizeCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SizeCommand::init_info()
    {
        auto w = writer<SizeCommand>();
        w.description("Size Command");
    }
}
