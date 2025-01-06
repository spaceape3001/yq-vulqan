////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/3D/3D.hpp>
#include <yt/3D/3DData.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <ya/spatials/SimpleSpatial3.hpp>

namespace yq::tachyon {
    ③Data::③Data()
    {
    }
    
    ③Data::~③Data()
    {
    }

    ③Snap::③Snap()
    {
    }
    
    ③Snap::~③Snap()
    {
    }
    

    ③::③()
    {
    }
    
    ③::~③()
    {
    }

    Tensor44D   ③::local2domain() const
    {
        return IDENTITY;
    }
    
    Tensor44D   ③::domain2local() const
    {
        return IDENTITY;
    }

    void    ③::finalize(③Data&d) const
    {
        И::finalize(d);
    }

    Spatial³ID    ③::make_simple_spatial(
        const Vector3D& position,
        const Quaternion3D& orientation,
        const Vector3D& scale
    ) {
        Tachyon* t  = dynamic_cast<Tachyon*>(this);
        if(t){
            SimpleSpatial³::Param p3;
            p3.position     = position;
            p3.orientation  = orientation;
            p3.scale        = scale;
            Spatial³ID      sid = t->create<SimpleSpatial³>(CHILD, p3) -> id();
            m_spatial       = sid;
            t->subscribe(m_spatial, MG::Spatial);
            return sid;
        }
        return {};
    }

    void    ③::snap(③Snap&sn) const
    {
        И::snap(sn);
    }
}

