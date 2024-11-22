////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Render3.hpp"
#include <yq/tachyon/api/Render3InfoWriter.hpp>
#include <yq/vector/Quaternion3.hxx>
#include <yq/tensor/Tensor44.hxx>

namespace yq::tachyon {

    Render³Info::Render³Info(std::string_view name, RenderedInfo& base, const std::source_location& sl) : 
        RenderedInfo(name, base, sl)
    {
        set(Flag::RENDER3D);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Render³::Render³(const Param&p) : Rendered(p)
    {
    }
    
    Render³::~Render³()   = default;


    Tensor44D   Render³::calc_local() const
    {
        return m_space.local2parent();
    }

    glm::dmat4  Render³::model2world() const
    {
        Tensor44D       T   = calc_local();
        for(const Render³* p = m_parent; p; p = p -> m_parent)
            T   = p->calc_local() * T;
        return T;
    }

    void        Render³::set_bounds(const AxBox3D&v)
    {
        m_bounds    = v;
    }

    void        Render³::set_heading(Radian hdg)
    {
        m_space.orientation  = rotor_z(hdg);
    }

    void        Render³::set_hpr(Radian hdg, Radian pitch, Radian roll)
    {
        m_space.orientation  = yq::hpr(hdg, pitch, roll);
    }

    void        Render³::set_orientation(const Quaternion3D&v)
    {
        m_space.orientation   = v;
    }

    void        Render³::set_position(const Vector3D&v)
    {
        m_space.position      = v;
    }
    
    void        Render³::set_scaling(double v)
    {
        m_space.scale        = { v, v, v };
    }

    void        Render³::set_scale(const Vector3D&v)
    {
        m_space.scale         = v;
    }

    void        Render³::set_space(const SimpleSpace&v)
    {
        m_space = v;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void    Render³::init_info()
    {
        auto w   = writer<Render³>();
        w.property("pos", &Render³::position).setter(&Render³::set_position);
        w.property("scale", &Render³::scale).setter(&Render³::set_scale);
        w.property("ori", &Render³::orientation).setter(&Render³::set_orientation);
        w.property("bounds", &Render³::bounds).setter(&Render³::set_bounds);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Render³)
