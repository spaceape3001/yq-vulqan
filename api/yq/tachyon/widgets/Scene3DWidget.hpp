////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Perspective.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {

    /*! \brief Widget for a scene
    
        Simple widget that allows for a camera & scene (render-frame)
    */
    class Scene3DWidget : public Widget {
        YQ_TACHYON_DECLARE(Scene3DWidget, Widget)
    public:
    
        //! Our perspective (ie, camera)
        Perspective     perspective;
        
        //! Our scene (ie, renders, lights, etc)
        Scene           scene;
    
        //! Default constructor
        Scene3DWidget();
        
        //! Default destructor
        virtual ~Scene3DWidget();
    
        //! Vulkan recording override
        virtual void    vulkan_(ViContext&) override;

        //! Pre-record (ie, for textures, UBOS)
        virtual void    prerecord(ViContext&) override;
        
        //! Adds a new thing to the scene (helper)
        void    add_thing(RenderedPtr);
        
        //! Sets the camera for us (helper)
        void    set_camera(CameraCPtr);
        
        static void init_info();
    };
}
