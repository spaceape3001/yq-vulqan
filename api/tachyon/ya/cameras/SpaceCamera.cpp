////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/cameras/SpaceCamera.hpp>
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

#include <yt/3D/Camera3InfoWriter.hpp>
//#include <ya/commands/CameraPitchCommand.hpp>

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

    void    SpaceCamera::snap(Camera³Snap&sn) const
    {
        sn.projection   = Tensor44D(projection_matrix(m_screen));
    }

    void SpaceCamera::init_info()
    {
        auto w = writer<SpaceCamera>();
        w.description("3D Space camera (fov with near/far plane)");
    }
}
YQ_TACHYON_IMPLEMENT(yq::tachyon::SpaceCamera)
