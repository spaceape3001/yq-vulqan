////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/3D/3D.hpp>
#include <yt/3D/3DData.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <tachyon/spatial/SimpleSpatial3.hpp>

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
            SimpleSpatial³*  ss³ = t->create_child<SimpleSpatial³>(p3);
            m_spatial       = ss³;
            t->subscribe(ss³->id(), MG::Spatial);
            return ss³->id();
        }
        return {};
    }

    void    ③::snap(③Snap&sn) const
    {
        И::snap(sn);
    }
}

