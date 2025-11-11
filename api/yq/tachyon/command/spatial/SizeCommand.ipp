////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

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

    void SizeCommand::init_meta()
    {
        auto w = writer<SizeCommand>();
        w.description("Size Command");
    }
}
