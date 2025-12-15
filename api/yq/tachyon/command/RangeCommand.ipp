////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/RangeCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeCommand)

namespace yq::tachyon {
    RangeCommand::RangeCommand(const Header& h) : Command(h)
    {
    }
    
    RangeCommand::RangeCommand(const RangeCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    RangeCommand::~RangeCommand()
    {
    }
    
    void RangeCommand::init_meta()
    {
        auto w = writer<RangeCommand>();
        w.abstract();
        w.description("Range Command");
    }
}
