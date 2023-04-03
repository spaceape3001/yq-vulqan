////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Target.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_projection.hpp>

namespace yq {
    namespace camera {
        Target::Target() : 
            m_position({0., 0., -10.}),
            m_target({0., 0., 0.}),
            m_up({0., 1., 0.}),
            m_fov(70_deg),
            m_near(0.1),
            m_far(20.)
        {
        }
        
        Target::~Target()
        {
        }
        
        glm::dmat4  Target::projection_matrix(const Size2D&sz) const
        {
            glm::dmat4 ret =  glm::perspective(
                                    (double) glm::radians(m_fov.value), 
                                    (double) sz.width() / (double) sz.height(),
                                    m_near, m_far
            );
            ret[1][1] *= -1;
            return ret;
        }

        void        Target::set_far(double v)
        {
            m_far   = v;
        }
        
        void        Target::set_near(double v)
        {
            m_near  = v;
        }
        
        
        void        Target::set_position(const Vector3D&v)
        {
            m_position    = v;
        }
        
        void        Target::set_fov(Degree v)
        {
            m_fov = v;
        }

        void        Target::set_target(const Vector3D&v)
        {
            m_target    = v;
        }
        
        void        Target::set_up(const Vector3D& v)
        {
            m_up        = v;
        }

        glm::dmat4  Target::view_matrix() const
        {
            return glm::lookAt((glm::dvec3) m_position, (glm::dvec3) m_target, (glm::dvec3) m_up);
        }

        glm::dmat4  Target::world2screen(const Params&p) const
        {
            return projection_matrix(p.screen) * view_matrix();
        }
    }
}
YQ_OBJECT_IMPLEMENT(yq::camera::Target)
