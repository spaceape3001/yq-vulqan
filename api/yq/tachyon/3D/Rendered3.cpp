////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/3D/Rendered3.hpp>
#include <yq/tachyon/3D/Rendered3Bind.hpp>
#include <yq/tachyon/3D/Rendered3InfoWriter.hpp>
#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/tachyon/spatials/SimpleSpatial3.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/tensor/Tensor44.hxx>

namespace yq::tachyon {

    Rendered³Snap::Rendered³Snap() = default;
    Rendered³Snap::~Rendered³Snap() = default;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Rendered³Info::Rendered³Info(std::string_view name, RenderedInfo& base, const std::source_location& sl) : 
        RenderedInfo(name, base, sl)
    {
        set(Flag::RENDER3D);
        set(Type::Rendered³);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Rendered³::Rendered³(const Param&p) : Rendered(p)
    {
        if(!(is_nan(p.position) && is_nan(p.orientation) && is_nan(p.scale))){
            SimpleSpatial³::Param p3;
            p3.position     = p.position;
            p3.orientation  = p.orientation;
            p3.scale        = p.scale;
            m_spatial       = create<SimpleSpatial³>(CHILD, p3) -> id();
            subscribe(m_spatial, MG::Spatial);
        }
    }
    
    Rendered³::~Rendered³()   = default;

    PostAdvice  Rendered³::advise(const Post& pp) const 
    {
        PostAdvice pa = Rendered::advise(pp);
        if(!unspecified(pa))
            return pa;
        if(dynamic_cast<const SpatialCommand*>(&pp))
            return MG::Spatial;
        return {};
    }

    void    Rendered³::set_bounds(bounds³_t b)
    {
        m_bounds = b;
        mark();
    }
    
    void    Rendered³::set_spatial(Spatial³ID sid)
    {
        m_spatial   = sid;
        mark();
    }

    Spatial³ID    Rendered³::make_simple_spatial(
        const Vector3D& position,
        const Quaternion3D& orientation,
        const Vector3D& scale
    ) {
        SimpleSpatial³::Param p3;
        p3.position     = position;
        p3.orientation  = orientation;
        p3.scale        = scale;
        m_spatial       = create<SimpleSpatial³>(CHILD, p3) -> id();
        subscribe(m_spatial, MG::Spatial);
        return m_spatial;
    }

#if 0
    Tensor44D   Rendered³::calc_local() const
    {
        return m_space.local2parent();
    }

    glm::dmat4  Rendered³::model2world() const
    {
        Tensor44D       T   = calc_local();
        //for(const Rendered³* p = m_parent; p; p = p -> m_parent)
            //T   = p->calc_local() * T;
        return T;
    }

    void        Rendered³::set_bounds(const AxBox3D&v)
    {
        m_bounds    = v;
    }

    void        Rendered³::set_heading(Radian hdg)
    {
        m_space.orientation  = rotor_z(hdg);
    }

    void        Rendered³::set_hpr(Radian hdg, Radian pitch, Radian roll)
    {
        m_space.orientation  = yq::hpr(hdg, pitch, roll);
    }

    void        Rendered³::set_orientation(const Quaternion3D&v)
    {
        m_space.orientation   = v;
    }

    void        Rendered³::set_position(const Vector3D&v)
    {
        m_space.position      = v;
    }
    
    void        Rendered³::set_scaling(double v)
    {
        m_space.scale        = { v, v, v };
    }

    void        Rendered³::set_scale(const Vector3D&v)
    {
        m_space.scale         = v;
    }

    void        Rendered³::set_space(const SimpleSpace&v)
    {
        m_space = v;
    }
#endif

    void    Rendered³::snap(Rendered³Snap&sn) const
    {
        Rendered::snap(sn);
        sn.bounds       = m_bounds;
        sn.spatial      = m_spatial;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void    Rendered³::init_info()
    {
        auto w   = writer<Rendered³>();
        w.description("Rendered in 3D");
        //w.property("pos", &Rendered³::position).setter(&Rendered³::set_position);
        //w.property("scale", &Rendered³::scale).setter(&Rendered³::set_scale);
        //w.property("ori", &Rendered³::orientation).setter(&Rendered³::set_orientation);
        //w.property("bounds", &Rendered³::bounds).setter(&Rendered³::set_bounds);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Rendered³)
