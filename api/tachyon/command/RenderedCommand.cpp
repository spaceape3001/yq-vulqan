////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/RenderedCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RenderedCommand)

namespace yq::tachyon {
    RenderedCommand::RenderedCommand(const Header& h) : Command(h)
    {
    }
    
    RenderedCommand::RenderedCommand(const RenderedCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    RenderedCommand::~RenderedCommand()
    {
    }
    
    void RenderedCommand::init_meta()
    {
        auto w = writer<RenderedCommand>();
        w.abstract();
        w.description("Rendered Command");
    }
}
