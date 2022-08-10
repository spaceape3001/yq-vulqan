////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Render3D.hpp"
#include "RenderWriter.hpp"
#include <basic/DelayInit.hpp>
#include <basic/meta/Init.hpp>
#include <atomic>

namespace yq {
    namespace engine {

        Render3DInfo::Render3DInfo(std::string_view name, ObjectInfo& base, const std::source_location& sl) : 
            RenderedInfo(name, base, sl)
        {
            set_option(RENDER3D);
        }
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Render3D::Render3D() : m_parent(nullptr, this), m_children(this), m_space(this), m_bounds(nan_v<AxBox3D>, this)
        {
        }
        
        Render3D::~Render3D()   = default;


        Tensor44D   Render3D::calc_local() const
        {
            return m_space->local2parent();
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
            m_space.edit().orientation  = rotor_z(hdg);
        }

        void        Render3D::set_hpr(Radian hdg, Radian pitch, Radian roll)
        {
            m_space.edit().orientation  = yq::hpr(hdg, pitch, roll);
        }

        void        Render3D::set_orientation(const Quaternion3D&v)
        {
            m_space.edit().orientation   = v;
        }

        void        Render3D::set_position(const Vector3D&v)
        {
            m_space.edit().position      = v;
        }
        
        void        Render3D::set_scaling(double v)
        {
            m_space.edit().scale        = { v, v, v };
        }

        void        Render3D::set_scale(const Vector3D&v)
        {
            m_space.edit().scale         = v;
        }

        void        Render3D::set_space(const SimpleSpace&v)
        {
            m_space = v;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        YQ_INVOKE(
            auto robj   = writer<Render3D>();
            robj.property("pos", &Render3D::position).setter(&Render3D::set_position);
            robj.property("scale", &Render3D::scale).setter(&Render3D::set_scale);
            robj.property("ori", &Render3D::orientation).setter(&Render3D::set_orientation);
            robj.property("bounds", &Render3D::bounds).setter(&Render3D::set_bounds);
        )
    }
}

YQ_OBJECT_IMPLEMENT(yq::engine::Render3D)
