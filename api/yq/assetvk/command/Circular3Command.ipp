////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Circular3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Circular³Command)

namespace yq::tachyon {
    Circular³Command::Circular³Command(const Header& h) : SpatialCommand(h)
    {
    }
    
    Circular³Command::Circular³Command(const Circular³Command&cp, const Header&h) : SpatialCommand(cp, h)
    {
    }

    Circular³Command::~Circular³Command()
    {
    }
    
    void Circular³Command::init_meta()
    {
        auto w = writer<Circular³Command>();
        w.abstract();
        w.description("Circular³ Command");
    }
}
