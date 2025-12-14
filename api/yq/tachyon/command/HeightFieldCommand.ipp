////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/HeightFieldCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::HeightFieldCommand)

namespace yq::tachyon {
    HeightFieldCommand::HeightFieldCommand(const Header& h) : Command(h)
    {
    }
    
    HeightFieldCommand::HeightFieldCommand(const HeightFieldCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    HeightFieldCommand::~HeightFieldCommand()
    {
    }
    
    void HeightFieldCommand::init_meta()
    {
        auto w = writer<HeightFieldCommand>();
        w.abstract();
        w.description("HeightField Command");
    }
}
