////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Render3D.hpp"
#include <yq/tachyon/api/Render3DInfoWriter.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/tensor/Tensor44.hxx>

namespace yq::tachyon {

    Render3DInfo::Render3DInfo(std::string_view name, RenderedInfo& base, const std::source_location& sl) : 
        RenderedInfo(name, base, sl)
    {
        set(Flag::RENDER3D);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Render3D::Render3D(const Param&p) : Rendered(p)
    {
    }
    
    Render3D::~Render3D()   = default;


    Tensor44D   Render3D::calc_local() const
    {
        return m_space.local2parent();
    }

    glm::dmat4  Render3D::model2world() const
    {
        Tensor44D       T   = calc_local();
        for(const Render3D* p = m_parent; p; p = p -> m_parent)
            T   = p->calc_local() * T;
        return T;
    }

    void        Render3D::set_bounds(const AxBox3D&v)
    {
        m_bounds    = v;
    }

    void        Render3D::set_heading(Radian hdg)
    {
        m_space.orientation  = rotor_z(hdg);
    }

    void        Render3D::set_hpr(Radian hdg, Radian pitch, Radian roll)
    {
        m_space.orientation  = yq::hpr(hdg, pitch, roll);
    }

    void        Render3D::set_orientation(const Quaternion3D&v)
    {
        m_space.orientation   = v;
    }

    void        Render3D::set_position(const Vector3D&v)
    {
        m_space.position      = v;
    }
    
    void        Render3D::set_scaling(double v)
    {
        m_space.scale        = { v, v, v };
    }

    void        Render3D::set_scale(const Vector3D&v)
    {
        m_space.scale         = v;
    }

    void        Render3D::set_space(const SimpleSpace&v)
    {
        m_space = v;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void    Render3D::init_info()
    {
        auto w   = writer<Render3D>();
        w.property("pos", &Render3D::position).setter(&Render3D::set_position);
        w.property("scale", &Render3D::scale).setter(&Render3D::set_scale);
        w.property("ori", &Render3D::orientation).setter(&Render3D::set_orientation);
        w.property("bounds", &Render3D::bounds).setter(&Render3D::set_bounds);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Render3D)
