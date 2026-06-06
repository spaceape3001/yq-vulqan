////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NoPhysics.hpp"
#include <yq/tachyon/model/Physics.hpp>
#include <yq/tachyon/model/PhysicsData.hpp>
#include <yq/tachyon/model/PhysicsMetaWriter.hpp>

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
