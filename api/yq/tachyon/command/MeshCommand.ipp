////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/command/MeshCommand.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MeshCommand)

namespace yq::tachyon {
    MeshCommand::MeshCommand(const Header& h) : Command(h)
    {
    }
    
    MeshCommand::MeshCommand(const MeshCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    MeshCommand::~MeshCommand()
    {
    }
    
    void MeshCommand::init_meta()
    {
        auto w = writer<MeshCommand>();
        w.abstract();
        w.description("Mesh Command");
    }
}
