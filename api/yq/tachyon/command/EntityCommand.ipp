////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "EntityCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::EntityCommand)

namespace yq::tachyon {
    EntityCommand::EntityCommand(const Header& h) : Command(h)
    {
    }
    
    EntityCommand::EntityCommand(const EntityCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    EntityCommand::~EntityCommand()
    {
    }
    
    void EntityCommand::init_meta()
    {
        auto w = writer<EntityCommand>();
        w.abstract();
        w.description("Entity Command");
    }
}
