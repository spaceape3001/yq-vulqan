////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Camera.hpp>
#include <yq/math/SimpleSpace.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class TargetCamera : public Camera {
        YQ_TACHYON_DECLARE(TargetCamera, Camera)
    public:
    
        /*
            TargetCamera might go away in favor of attaching a 
            controller (basically an aimbot)
        */
    
        glm::dmat4  world2screen(const Values&) const override;
        TargetCamera(const Param&p = {});
        ~TargetCamera();

        double                  far() const { return m_far; }
        Degree                  fov() const { return m_fov; }
        double                  near() const { return m_near; }
        const Vector3D&         position() const { return m_position; }
        const Vector3D&         target() const { return m_target; }
        const Vector3D&         up() const { return m_up; }

        glm::dmat4              projection_matrix(const Rectangle2D&) const;

        void                    set_far(double);
        void                    set_near(double);
        void                    set_position(const Vector3D&);
        void                    set_fov(Degree);
        void                    set_target(const Vector3D&);
        void                    set_up(const Vector3D&);
        glm::dmat4              view_matrix() const;

    private:
        Vector3D       m_position;
        Vector3D       m_target;
        Vector3D       m_up;
        Degree         m_fov;
        double         m_near;
        double         m_far;
    };
}
