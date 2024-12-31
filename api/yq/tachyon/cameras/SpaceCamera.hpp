////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/scene/Camera3.hpp>
#include <yq/math/SimpleSpace.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {

    class CameraPitchCommand;

    /*! \brief Camera in 3D space
    
        This is a simple camera that has a position, orientation
        as defined in the simple space object.  It's got near and
        far, along with a POV angle.
    */
    class SpaceCamera : public Camera³ {
        YQ_TACHYON_DECLARE(SpaceCamera, Camera³)
    public:
    
        //! \brief World to screen matrix
        //! This routine returns the relevant world to screen projection matrix
        //glm::dmat4  world2screen(const Values&) const override;
        
        //! Default constructor
        SpaceCamera(const Param&p = {});
        
        //! Default destructor
        ~SpaceCamera();

        //! Distance to the "far" plane
        double                  far() const { return m_far; }
        
        //! Our angle of view
        Degree                  fov() const { return m_fov; }
        
        //! Distance to the near plane
        double                  near() const { return m_near; }
        
        //! Our orientation in 3D space
        const Quaternion3D&     orientation() const { return m_space.orientation; }
        
        //! Our position in 3D space
        const Vector3D&         position() const { return m_space.position; }

        //! Computes the projection matrix for a given rectangle (ie camera XYZ -> screen)
        glm::dmat4              projection_matrix(const Rectangle2D&) const;
        
        //! Gets our scale
        const Vector3D&         scale() const { return m_space.scale; }

        //! Sets the distance to the far plane
        void                    set_far(double);
        
        //! Sets the distance to the  near plane
        void                    set_near(double);
        
        //! Sets our orientation
        void                    set_orientation(const Quaternion3D&);
        
        //! Sets our position
        void                    set_position(const Vector3D&);
        
        //! Sets our scale
        void                    set_scale(const Vector3D&);
        
        //! Sets the field-of-view angle
        void                    set_fov(Degree);
        
        //! Computes the view matrix (ie, space -> camera XYZ)
        glm::dmat4              view_matrix() const;
        
        static void init_info();

    private:
        SimpleSpace    m_space;
        Degree         m_fov;
        double         m_near;
        double         m_far;
        
        void            pitch_command(const CameraPitchCommand&);
    };
}
