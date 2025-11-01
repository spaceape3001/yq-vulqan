////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/2D.hpp>
#include <tachyon/api/2DData.hpp>
#include <yq/tensor/Tensor44.hpp>
//#include <tachyon/spatial/SimpleSpatial2.hpp>

namespace yq::tachyon {
    ②Data::②Data()
    {
    }
    
    ②Data::~②Data()
    {
    }

    ②Snap::②Snap()
    {
    }
    
    ②Snap::~②Snap()
    {
    }
    

    ②::②()
    {
    }
    
    ②::~②()
    {
    }

    void    ②::finalize(②Data&d) const
    {
        И::finalize(d);
    }

#if 0
    Spatial³ID    ②::make_simple_spatial(
        const Vector2D& position,
        const Quaternion2D& orientation,
        const Vector2D& scale
    ) {
        Tachyon* t  = dynamic_cast<Tachyon*>(this);
        if(t){
            SimpleSpatial³::Param p2;
            p2.position     = position;
            p2.orientation  = orientation;
            p2.scale        = scale;
            SimpleSpatial³*  ss³ = t->create_child<SimpleSpatial³>(p2);
            m_spatial       = ss³;
            t->subscribe(ss³->id(), MG::Spatial);
            return ss³->id();
        }
        return {};
    }
#endif

    void    ②::snap(②Snap&sn) const
    {
        И::snap(sn);
    }
}

