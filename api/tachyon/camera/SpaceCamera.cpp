////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/camera/SpaceCamera.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_projection.hpp>

#include <yq/math/trigonometry.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <yq/vector/Vector3.hxx>

#include <yq/shape/Rectangle2.hxx>
#include <yq/shape/Size2.hxx>
#include <yq/tensor/Tensor44.hxx>
#include <yq/vector/Quaternion3.hxx>

#include <yt/3D/Camera3InfoWriter.hpp>
//#include <tachyon/command/CameraPitchCommand.hpp>

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
        Camera³::snap(sn);
        
        double  tangent = tan(m_fov/2.);
        double  aspect  = m_screen.size.y / m_screen.size.x;
        double  right   = m_near * tangent;
        double  top     = right * m_screen.size.y / m_screen.size.x;
        //double  fnear      = (m_far+m_near)/(m_far-m_near);
        
        
            /*
                PROJECTION MATRIX ...
                
                At view = IDENTITY... we want...
                
                Facing +X direction
                "Up" is -Z
                "Left" is -Y
                "Right" is +Y

                Using http://www.songho.ca/opengl/gl_projectionmatrix.html as the guide
                
                AND...
                
                Vulkan defaults to a right-handed coordinate system with 
                +X right
                +Y down, 
                +Z into screen (open GL does it out)
                
                Consider the screen space as "u,v,w" coordinate system, with n/f as near/far
                
                IDENTITY... due north (ie, +X)
                
                

            */
        
        sn.projection.xx = 0.;
        sn.projection.xy = m_screen.size.y / (m_screen.size.x * tangent);
        sn.projection.xz = 0.;
        sn.projection.xw = 0.;

        sn.projection.yx = 0.;
        sn.projection.yy = 0.;
        sn.projection.yz = 1. / tangent;
        sn.projection.yw = 0.;

        sn.projection.zx = (m_far+m_near)/(m_far-m_near);
        sn.projection.zy = 0.;
        sn.projection.zz = 0.;
        sn.projection.zw = -2.*(m_far*m_near)/(m_far-m_near);
        
        sn.projection.wx =  1.;
        sn.projection.wy =  0.;
        sn.projection.wz =  0.;
        sn.projection.ww =  0.;
        
        //sn.projection   = Tensor44D(projection_matrix(m_screen));
    }

    void SpaceCamera::init_info()
    {
        auto w = writer<SpaceCamera>();
        w.description("3D Space camera (fov with near/far plane)");
    }
}
YQ_TACHYON_IMPLEMENT(yq::tachyon::SpaceCamera)
