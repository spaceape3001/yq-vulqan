////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/spatial/AABBCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AABBCommand)

namespace yq::tachyon {

    AABBCommand::AABBCommand(const Header&h) : SpatialCommand(h)
    {
    }

    AABBCommand::AABBCommand(const AABBCommand& cp, const Header& h) : SpatialCommand(cp, h)
    {
    }
    
    AABBCommand::~AABBCommand()
    {
    }

    PostCPtr    AABBCommand::clone(rebind_k, const Header&h) const 
    {
        return new AABBCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void AABBCommand::init_meta()
    {
        auto w = writer<AABBCommand>();
        w.description("AABB Command");
    }
}
