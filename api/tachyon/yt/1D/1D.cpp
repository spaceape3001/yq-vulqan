////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/1D/1D.hpp>
#include <yt/1D/1DData.hpp>

namespace yq::tachyon {
    ①Data::①Data()
    {
    }
    
    ①Data::~①Data()
    {
    }

    ①Snap::①Snap()
    {
    }
    
    ①Snap::~①Snap()
    {
    }
    

    ①::①()
    {
    }
    
    ①::~①()
    {
    }

    void    ①::finalize(①Data&d) const
    {
        И::finalize(d);
    }

#if 0
    Spatial³ID    ①::make_simple_spatial(
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

    void    ①::snap(①Snap&sn) const
    {
        И::snap(sn);
    }
}

