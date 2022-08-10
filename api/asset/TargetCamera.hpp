////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/Camera.hpp>
#include <basic/Mutable.hpp>
#include <math/SimpleSpace.hpp>
#include <math/Units.hpp>

namespace yq {
    namespace asset {
        class TargetCamera : public engine::Camera {
            YQ_OBJECT_DECLARE(TargetCamera, engine::Camera)
        public:
        
            glm::dmat4  world2screen(const engine::CameraParams&) const override;
            TargetCamera();
            ~TargetCamera();

            double                  far() const { return m_far; }
            Degree                  fov() const { return m_fov; }
            double                  near() const { return m_near; }
            const Vector3D&         position() const { return m_position; }
            const Vector3D&         target() const { return m_target; }
            const Vector3D&         up() const { return m_up; }

            glm::dmat4              projection_matrix(const Size2D&) const;

            void                    set_far(double);
            void                    set_near(double);
            void                    set_position(const Vector3D&);
            void                    set_fov(Degree);
            void                    set_target(const Vector3D&);
            void                    set_up(const Vector3D&);
            glm::dmat4              view_matrix() const;

        private:
            Mutable<Vector3D>       m_position;
            Mutable<Vector3D>       m_target;
            Mutable<Vector3D>       m_up;
            Mutable<Degree>         m_fov;
            Mutable<double>         m_near;
            Mutable<double>         m_far;
        };
    }
}
