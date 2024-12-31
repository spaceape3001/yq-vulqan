////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Rendered3.hpp"
#include <yq/tachyon/api/Rendered3InfoWriter.hpp>
#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/tachyon/spatials/SimpleSpatial3.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/tensor/Tensor44.hxx>

namespace yq::tachyon {

    Rendered3Snap::Rendered3Snap() = default;
    Rendered3Snap::~Rendered3Snap() = default;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Rendered3Info::Rendered3Info(std::string_view name, RenderedInfo& base, const std::source_location& sl) : 
        RenderedInfo(name, base, sl)
    {
        set(Flag::RENDER3D);
        set(Type::Rendered3);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Rendered3::Rendered3(const Param&p) : Rendered(p)
    {
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            SimpleSpatial3::Param p3;
            p3.position     = p.position;
            p3.orientation  = p.orientation;
            p3.scale        = p.scale;
            m_spatial       = create<SimpleSpatial3>(CHILD, p3) -> id();
            subscribe(m_spatial, MG::Spatial);
        }
    }
    
    Rendered3::~Rendered3()   = default;

    PostAdvice  Rendered3::advise(const Post& pp) const 
    {
        PostAdvice pa = Rendered::advise(pp);
        if(!unspecified(pa))
            return pa;
        if(dynamic_cast<const SpatialCommand*>(&pp))
            return MG::Spatial;
        return {};
    }

    void    Rendered3::set_bounds(bounds3_t b)
    {
        m_bounds = b;
        mark();
    }
    
    void    Rendered3::set_spatial(Spatial3ID sid)
    {
        m_spatial   = sid;
        mark();
    }

    void    Rendered3::set_spatial(
        const Vector3D& position,
        const Quaternion3D& orientation,
        const Vector3D& scale
    ) {
        SimpleSpatial3::Param p3;
        p3.position     = position;
        p3.orientation  = orientation;
        p3.scale        = scale;
        m_spatial       = create<SimpleSpatial3>(CHILD, p3) -> id();
        subscribe(m_spatial, MG::Spatial);
    }

#if 0
    Tensor44D   Rendered3::calc_local() const
    {
        return m_space.local2parent();
    }

    glm::dmat4  Rendered3::model2world() const
    {
        Tensor44D       T   = calc_local();
        //for(const Rendered3* p = m_parent; p; p = p -> m_parent)
            //T   = p->calc_local() * T;
        return T;
    }

    void        Rendered3::set_bounds(const AxBox3D&v)
    {
        m_bounds    = v;
    }

    void        Rendered3::set_heading(Radian hdg)
    {
        m_space.orientation  = rotor_z(hdg);
    }

    void        Rendered3::set_hpr(Radian hdg, Radian pitch, Radian roll)
    {
        m_space.orientation  = yq::hpr(hdg, pitch, roll);
    }

    void        Rendered3::set_orientation(const Quaternion3D&v)
    {
        m_space.orientation   = v;
    }

    void        Rendered3::set_position(const Vector3D&v)
    {
        m_space.position      = v;
    }
    
    void        Rendered3::set_scaling(double v)
    {
        m_space.scale        = { v, v, v };
    }

    void        Rendered3::set_scale(const Vector3D&v)
    {
        m_space.scale         = v;
    }

    void        Rendered3::set_space(const SimpleSpace&v)
    {
        m_space = v;
    }
#endif

    void    Rendered3::snap(Rendered3Snap&sn) const
    {
        Rendered::snap(sn);
        sn.bounds       = m_bounds;
        sn.spatial      = m_spatial;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void    Rendered3::init_info()
    {
        auto w   = writer<Rendered3>();
        w.description("Rendered in 3D");
        //w.property("pos", &Rendered3::position).setter(&Rendered3::set_position);
        //w.property("scale", &Rendered3::scale).setter(&Rendered3::set_scale);
        //w.property("ori", &Rendered3::orientation).setter(&Rendered3::set_orientation);
        //w.property("bounds", &Rendered3::bounds).setter(&Rendered3::set_bounds);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Rendered3)
