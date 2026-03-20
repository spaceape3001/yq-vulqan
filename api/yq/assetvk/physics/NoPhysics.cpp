////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "NoPhysics.hpp"
#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/api/PhysicsData.hpp>
#include <yq/tachyon/api/PhysicsMetaWriter.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/vector/Vector3.hpp>

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
        // These implementations will likely move to an aspect....
        sn.screen2map   = [sc=m_scale](const Meter2D& pt) -> Vector2D {
            return { 
                pt.x.value/sc.value,
                pt.y.value/sc.value
            };
        };
        
        sn.screen2rev   = [sc=m_scale](const Vector2D& v) -> Meter2D {
            return {
                v.x * sc,
                v.y * sc
            };
        };

        sn.screen3map   = [sc=m_scale](const Meter3D& pt) -> Vector3D {
            return { 
                pt.x.value/sc.value,
                pt.y.value/sc.value,
                pt.z.value/sc.value
            };
        };

        sn.screen3rev   = [sc=m_scale](const Vector3D& v) -> Meter3D {
            return {
                v.x * sc,
                v.y * sc,
                v.z * sc
            };
        };
    }

    void NoPhysics::init_meta()
    {
        auto w = writer<NoPhysics>();
        w.description("No physics, aside from scale");
    }
}
