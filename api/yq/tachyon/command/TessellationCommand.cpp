////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/TessellationCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TessellationCommand)

namespace yq::tachyon {
    TessellationCommand::TessellationCommand(const Header& h) : Command(h)
    {
    }
    
    TessellationCommand::TessellationCommand(const TessellationCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    TessellationCommand::~TessellationCommand()
    {
    }
    
    void TessellationCommand::init_meta()
    {
        auto w = writer<TessellationCommand>();
        w.abstract();
        w.description("Tessellation Command");
    }
}
