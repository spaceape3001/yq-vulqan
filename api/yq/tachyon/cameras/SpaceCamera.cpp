////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SpaceCamera.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_projection.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <yq/vector/Vector3.hxx>

#include <yq/shape/Rectangle2.hxx>
#include <yq/shape/Size2.hxx>
#include <yq/tensor/Tensor44.hxx>
#include <yq/vector/Quaternion3.hxx>

#include <yq/tachyon/commands/CameraPitchCommand.hpp>
#include <yq/tachyon/scene/Camera3InfoWriter.hpp>

namespace yq::tachyon {
    SpaceCamera::SpaceCamera(const Param&p) : Camera³(p),
        m_fov(70_deg),
        m_near(0.1),
        m_far(10.)
    {
    }
    
    SpaceCamera::~SpaceCamera()
    {
    }
    
    void        SpaceCamera::pitch_command(const CameraPitchCommand& amt)
    {
        m_space.orientation = rotor_y(amt.angle()) * m_space.orientation;
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

#if 0
    glm::dmat4  SpaceCamera::world2screen(const Values&p) const
    {
        return projection_matrix(p.screen) * view_matrix();
    }
#endif

    void SpaceCamera::init_info()
    {
        auto w = writer<SpaceCamera>();
        w.description("Simple space camera (position, orientation, fov)");
        w.slot(&SpaceCamera::pitch_command);
    }
}
YQ_TACHYON_IMPLEMENT(yq::tachyon::SpaceCamera)
