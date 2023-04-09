////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SpaceCamera.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_projection.hpp>
#include <math/shape/Rectangle2.hpp>
#include <math/vector/Tensor44.hpp>
#include <math/vector/Vector3.hpp>


namespace yq {
    namespace tachyon {
        SpaceCamera::SpaceCamera() : 
            m_fov(70_deg),
            m_near(0.1),
            m_far(10.)
        {
        }
        
        SpaceCamera::~SpaceCamera()
        {
        }
        
        glm::dmat4  SpaceCamera::projection_matrix(const Rectangle2D&sz) const
        {
            //  ignore the translation (for now)
            glm::dmat4 ret =  glm::perspective(
                                    (double) glm::radians(m_fov.value), 
                                    (double) sz.width() / (double) sz.height(),
                                    m_near, m_far
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
            m_space.orientation = v;
        }
        
        void        SpaceCamera::set_position(const Vector3D&v)
        {
            m_space.position    = v;
        }
        
        void        SpaceCamera::set_scale(const Vector3D&v)
        {
            m_space.scale       = v;
        }
        
        void        SpaceCamera::set_fov(Degree v)
        {
            m_fov = v;
        }

        glm::dmat4  SpaceCamera::view_matrix() const
        {
            return m_space.parent2local();
        }

        glm::dmat4  SpaceCamera::world2screen(const Params&p) const
        {
            return projection_matrix(p.screen) * view_matrix();
        }
    }
}
YQ_OBJECT_IMPLEMENT(yq::tachyon::SpaceCamera)
