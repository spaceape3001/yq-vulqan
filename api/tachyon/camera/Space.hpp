////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Camera.hpp>
#include <math/SimpleSpace.hpp>
#include <math/units.hpp>

namespace yq {
    namespace camera {
        class Space : public Camera {
            YQ_OBJECT_DECLARE(Space, Camera)
        public:
        
            glm::dmat4  world2screen(const Params&) const override;
            Space();
            ~Space();

            double                  far() const { return m_far; }
            Degree                  fov() const { return m_fov; }
            double                  near() const { return m_near; }
            const Quaternion3D&     orientation() const { return m_space.orientation; }
            const Vector3D&         position() const { return m_space.position; }

            glm::dmat4              projection_matrix(const Size2D&) const;
            const Vector3D&         scale() const { return m_space.scale; }

            void                    set_far(double);
            void                    set_near(double);
            void                    set_orientation(const Quaternion3D&);
            void                    set_position(const Vector3D&);
            void                    set_scale(const Vector3D&);
            void                    set_fov(Degree);
            glm::dmat4              view_matrix() const;

        private:
            SimpleSpace    m_space;
            Degree         m_fov;
            double         m_near;
            double         m_far;
        };
    }
}
