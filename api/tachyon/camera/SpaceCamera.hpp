////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Camera3.hpp>
#include <yq/math/SimpleSpace.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {

    class CameraPitchCommand;

    /*! \brief Camera in 3D space
    
        This is a simple camera that has a near plane, a far plane, and
        a POV angle.
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
        
        //! Computes the projection matrix for a given rectangle (ie camera XYZ -> screen)
        glm::dmat4              projection_matrix(const Rectangle2D&) const;
        
        //! Sets the distance to the far plane
        void                    set_far(double);
        
        //! Sets the distance to the  near plane
        void                    set_near(double);
        
        //! Sets the field-of-view angle
        void                    set_fov(Degree);
        
        static void init_info();
        
    protected:
        void    snap(Camera³Snap&) const;

    private:
        Degree         m_fov;
        double         m_near;
        double         m_far;
        
        void           pitch_command(const CameraPitchCommand&);
    };
}
