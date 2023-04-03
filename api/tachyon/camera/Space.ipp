////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Space.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_projection.hpp>
#include <math/vector/Tensor44.hxx>
#include <math/vector/Vector3.hxx>


namespace yq {
    namespace camera {
        Space::Space() : 
            m_fov(70_deg),
            m_near(0.1),
            m_far(10.)
        {
        }
        
        Space::~Space()
        {
        }
        
        glm::dmat4  Space::projection_matrix(const Size2D&sz) const
        {
            glm::dmat4 ret =  glm::perspective(
                                    (double) glm::radians(m_fov.value), 
                                    (double) sz.width() / (double) sz.height(),
                                    m_near, m_far
            );
            ret[1][1] *= -1;
            return ret;
        }

        void        Space::set_far(double v)
        {
            m_far   = v;
        }
        
        void        Space::set_near(double v)
        {
            m_near  = v;
        }
        
        void        Space::set_orientation(const Quaternion3D&v)
        {
            m_space.orientation = v;
        }
        
        void        Space::set_position(const Vector3D&v)
        {
            m_space.position    = v;
        }
        
        void        Space::set_scale(const Vector3D&v)
        {
            m_space.scale       = v;
        }
        
        void        Space::set_fov(Degree v)
        {
            m_fov = v;
        }

        glm::dmat4  Space::view_matrix() const
        {
            return m_space.parent2local();
        }

        glm::dmat4  Space::world2screen(const Params&p) const
        {
            return projection_matrix(p.screen) * view_matrix();
        }
    }
}
YQ_OBJECT_IMPLEMENT(yq::camera::Space)
