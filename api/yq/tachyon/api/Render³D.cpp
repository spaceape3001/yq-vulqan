////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Render³D.hpp"
#include <yq/tachyon/api/Render³DInfoWriter.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/tensor/Tensor44.hxx>

namespace yq::tachyon {

    Render³DInfo::Render³DInfo(std::string_view name, RenderedInfo& base, const std::source_location& sl) : 
        RenderedInfo(name, base, sl)
    {
        set(Flag::RENDER3D);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Render³D::Render³D(const Param&p) : Rendered(p)
    {
    }
    
    Render³D::~Render³D()   = default;


    Tensor44D   Render³D::calc_local() const
    {
        return m_space.local2parent();
    }

    glm::dmat4  Render³D::model2world() const
    {
        Tensor44D       T   = calc_local();
        for(const Render³D* p = m_parent; p; p = p -> m_parent)
            T   = p->calc_local() * T;
        return T;
    }

    void        Render³D::set_bounds(const AxBox3D&v)
    {
        m_bounds    = v;
    }

    void        Render³D::set_heading(Radian hdg)
    {
        m_space.orientation  = rotor_z(hdg);
    }

    void        Render³D::set_hpr(Radian hdg, Radian pitch, Radian roll)
    {
        m_space.orientation  = yq::hpr(hdg, pitch, roll);
    }

    void        Render³D::set_orientation(const Quaternion3D&v)
    {
        m_space.orientation   = v;
    }

    void        Render³D::set_position(const Vector3D&v)
    {
        m_space.position      = v;
    }
    
    void        Render³D::set_scaling(double v)
    {
        m_space.scale        = { v, v, v };
    }

    void        Render³D::set_scale(const Vector3D&v)
    {
        m_space.scale         = v;
    }

    void        Render³D::set_space(const SimpleSpace&v)
    {
        m_space = v;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void    Render³D::init_info()
    {
        auto w   = writer<Render³D>();
        w.property("pos", &Render³D::position).setter(&Render³D::set_position);
        w.property("scale", &Render³D::scale).setter(&Render³D::set_scale);
        w.property("ori", &Render³D::orientation).setter(&Render³D::set_orientation);
        w.property("bounds", &Render³D::bounds).setter(&Render³D::set_bounds);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Render³D)
