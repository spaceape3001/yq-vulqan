////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SpaceCamera.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_projection.hpp>

namespace yq {
    namespace asset {
        SpaceCamera::SpaceCamera() : 
            m_space(this),
            m_fov(70_deg, this),
            m_near(0.1, this),
            m_far(10., this)
        {
        }
        
        SpaceCamera::~SpaceCamera()
        {
        }
        
        glm::dmat4  SpaceCamera::projection_matrix(const Size2D&sz) const
        {
            glm::dmat4 ret =  glm::perspective(
                                    (double) glm::radians(m_fov.get().value), 
                                    (double) sz.width() / (double) sz.height(),
                                    m_near.get(), m_far.get()
            );
            ret[1][1] *= -1;
            return ret;
        }

        void        SpaceCamera::set_far(double v)
        {
            m_far   = v;
        }
        
        void        SpaceCamera::set_near(double v)
        {
            m_near  = v;
        }
        
        void        SpaceCamera::set_orientation(const Quaternion3D&v)
        {
            m_space.edit().orientation = v;
        }
        
        void        SpaceCamera::set_position(const Vector3D&v)
        {
            m_space.edit().position    = v;
        }
        
        void        SpaceCamera::set_scale(const Vector3D&v)
        {
            m_space.edit().scale       = v;
        }
        
        void        SpaceCamera::set_fov(Degree v)
        {
            m_fov = v;
        }

        glm::dmat4  SpaceCamera::view_matrix() const
        {
            return m_space->parent2local();
        }

        glm::dmat4  SpaceCamera::world2screen(const engine::CameraParams&p) const
        {
            return projection_matrix(p.screen) * view_matrix();
        }
    }
}
YQ_OBJECT_IMPLEMENT(yq::asset::SpaceCamera)
