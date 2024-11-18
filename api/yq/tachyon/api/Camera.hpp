////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/math/glm.hpp>
#include <yq/tachyon/core/Tachyon.hpp>
#include <yq/tachyon/typedef/camera.hpp>

namespace yq::tachyon {

    class Camera;
    
    /*! \brief Camera Information
    
        Information for cameras.
    */
    class CameraInfo : public TachyonInfo {
    public:
        template <typename C> struct Writer;

        //! Gets all camera informations
        static const std::vector<const CameraInfo*>&    all();
        
        //! Standard constructor for the camera information
        CameraInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    private:
    
        // This *may* go into toolbox... some common "dynamic creation kit"
        struct Repo;
        static Repo& repo();
    };


    /*! \brief Shows up on the screen
    
        If you want it to show up on the viewport, it needs to be renderable, and thus derived
        from this thing.  
        
        \note We're limited to three dimensions here
    */
    class Camera : public Tachyon {
        YQ_OBJECT_INFO(CameraInfo);
        YQ_OBJECT_DECLARE(Camera, Tachyon)
    public:    
        /*
            We *MIGHT* want to divide up the camera into position, 
            lens, etc... or that's a later development on a dedicated
            camera.  (class DynamicCamera, StandardCamera, etc???)
        */
    
    
        //! Generic parameter structure
        //! Allows us to expand parameters w/o affecting *everybody*
        struct Values;
    
        //! Returns the transform to go world -> screen space
        virtual glm::dmat4  world2screen(const Values&) const = 0;
    
        //! Name of this camera's instance
        std::string_view    name() const { return m_name; }
        
        //! Getter for the property system
        const std::string&  get_name() const { return m_name; }
        
        //! Sets the camera's name
        void                set_name(const std::string&);

        static void init_info();

        virtual void tick();
        
        

    protected:
    
        virtual void    snap(CameraData&) const override;
        virtual void    receive(const post::PostCPtr&) override;

        //! Default constructor
        Camera();
        
        //! Default destructor
        ~Camera();
        
    private:
        std::string         m_name;
    };

    /*! \brief Camera parameters
    */
    struct Camera::Values {
        //  Dimensions of the screen
        Rectangle2D     screen;
    };
}
