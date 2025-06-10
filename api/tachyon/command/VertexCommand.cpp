////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/VertexCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::VertexCommand)

namespace yq::tachyon {
    VertexCommand::VertexCommand(const Header& h) : Command(h)
    {
    }
    
    VertexCommand::VertexCommand(const VertexCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    VertexCommand::~VertexCommand()
    {
    }
    
    void VertexCommand::init_info()
    {
        auto w = writer<VertexCommand>();
        w.abstract();
        w.description("Vertex Command");
    }
}
