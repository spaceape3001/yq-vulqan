////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PhysicsCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PhysicsCommand)

namespace yq::tachyon {
    PhysicsCommand::PhysicsCommand(const Header& h) : Command(h)
    {
    }
    
    PhysicsCommand::PhysicsCommand(const PhysicsCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    PhysicsCommand::~PhysicsCommand()
    {
    }
    
    void PhysicsCommand::init_meta()
    {
        auto w = writer<PhysicsCommand>();
        w.abstract();
        w.description("Physics Command");
    }
}
