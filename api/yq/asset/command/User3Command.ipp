////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "User3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::User³Command)

namespace yq::tachyon {
    User³Command::User³Command(const Header& h) : SpatialCommand(h)
    {
    }
    
    User³Command::User³Command(const User³Command&cp, const Header&h) : SpatialCommand(cp, h)
    {
    }

    User³Command::~User³Command()
    {
    }
    
    void User³Command::init_meta()
    {
        auto w = writer<User³Command>();
        w.abstract();
        w.description("User³ Command");
    }
}
