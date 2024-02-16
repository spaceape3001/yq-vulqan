////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Widget.hpp>
#include <tachyon/Perspective.hpp>
#include <tachyon/Scene.hpp>

namespace yq::tachyon {

    /*! \brief Widget for a scene
    
        Simple widget that allows for a camera & scene (render-frame)
    */
    class Scene3D : public Widget {
        YQ_OBJECT_DECLARE(Scene3D, Widget)
    public:
    
        //! Our perspective (ie, camera)
        Perspective     perspective;
        
        //! Our scene (ie, renders, lights, etc)
        Scene           scene;
    
        //! Default constructor
        Scene3D();
        
        //! Default destructor
        virtual ~Scene3D();
    
        //! Vulkan recording override
        virtual void    vulkan_(ViContext&) override;

        //! Pre-record (ie, for textures, UBOS)
        virtual void    prerecord(ViContext&) override;
        
        //! Adds a new thing to the scene (helper)
        void    add_thing(RenderedPtr);
        
        //! Sets the camera for us (helper)
        void    set_camera(CameraCPtr);
    };
}
