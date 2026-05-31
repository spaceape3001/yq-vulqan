////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Mesh3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Mesh³Command)

namespace yq::tachyon {
    Mesh³Command::Mesh³Command(const Header& h) : SpatialCommand(h)
    {
    }
    
    Mesh³Command::Mesh³Command(const Mesh³Command&cp, const Header&h) : SpatialCommand(cp, h)
    {
    }

    Mesh³Command::~Mesh³Command()
    {
    }
    
    void Mesh³Command::init_meta()
    {
        auto w = writer<Mesh³Command>();
        w.abstract();
        w.description("Mesh³ Command");
    }
}
