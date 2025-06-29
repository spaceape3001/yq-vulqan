////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Camera3.hpp>
#include <tachyon/aspect/AFarPlane.hpp>
#include <tachyon/aspect/AFieldOfView.hpp>
#include <tachyon/aspect/ANearPlane.hpp>
#include <yq/math/SimpleSpace.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {

    /*! \brief Camera in 3D space
    
        This is a simple camera that has a near plane, a far plane, and
        a POV angle. 
        
        \note Combining this with a simple spatial yields a NORTH-EAST-DOWN
        perspective!
    */
    class SpaceCamera : public Camera³, public AFieldOfView, public AFarPlane, public ANearPlane {
        YQ_TACHYON_DECLARE(SpaceCamera, Camera³)
    public:
    
        using AFieldOfView::field_of_view;
    
        struct Param : public Camera³::Param {
            Degree  fov     = 70_deg;
            double  near    = 0.1;
            double  far     = 60.0;
            
            Param(){}
        };
        
        virtual bool field_of_view(settable_k) const override { return true; }
        virtual bool near_plane(settable_k) const override { return true; }
        virtual bool far_plane(settable_k) const override { return true; }
    
        //! \brief World to screen matrix
        //! This routine returns the relevant world to screen projection matrix
        //glm::dmat4  world2screen(const Values&) const override;
        
        //! Default constructor
        SpaceCamera(const Param&p = Param());
        
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
    };
}

YQ_TACHYON_FORCE(yq::tachyon::SpaceCamera)
