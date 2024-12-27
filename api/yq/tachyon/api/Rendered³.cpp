////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Rendered³.hpp"
#include <yq/tachyon/api/Rendered³InfoWriter.hpp>
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
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Rendered³::Rendered³(const Param&p) : Rendered(p)
    {
    }
    
    Rendered³::~Rendered³()   = default;


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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void    Rendered³::init_info()
    {
        auto w   = writer<Rendered³>();
        w.property("pos", &Rendered³::position).setter(&Rendered³::set_position);
        w.property("scale", &Rendered³::scale).setter(&Rendered³::set_scale);
        w.property("ori", &Rendered³::orientation).setter(&Rendered³::set_orientation);
        w.property("bounds", &Rendered³::bounds).setter(&Rendered³::set_bounds);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Rendered³)
