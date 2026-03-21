////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NoPhysics.hpp"
#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/api/PhysicsData.hpp>
#include <yq/tachyon/api/PhysicsMetaWriter.hpp>
#include <yq/tachyon/aspect/AScreenScaleMWriter.hxx>

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
        AScreenScaleM::snap(sn);
    }

    void NoPhysics::init_meta()
    {
        auto w = writer<NoPhysics>();
        AScreenScaleM::init_meta(w);
        w.description("No physics, aside from scale");
    }
}
