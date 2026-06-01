////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NoPhysics.hpp"
#include <yq/physicsvk/api/Physics.hpp>
#include <yq/physicsvk/api/PhysicsData.hpp>
#include <yq/physicsvk/api/PhysicsMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::NoPhysics)

namespace yq::tachyon {
    NoPhysics::NoPhysics()
    {
    }
    
    NoPhysics::~NoPhysics()
    {
    }
        
    void NoPhysics::snap(PhysicsSnap& sn) const
    {
        Physics::snap(sn);
    }

    void NoPhysics::init_meta()
    {
        auto w = writer<NoPhysics>();
        w.description("No physics");
    }
}
