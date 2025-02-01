////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/scene/Perspective.hpp>
#include <yt/scene/Scene.hpp>
#include <yt/ui/Widget.hpp>

namespace yq::tachyon {

    /*! \brief Widget for a scene
    
        Simple widget that allows for a camera & scene (render-frame)
    */
    class Scene3DWidget0 : public Widget {
        YQ_TACHYON_DECLARE(Scene3DWidget0, Widget)
    public:
    
        //! Our perspective (ie, camera)
        Perspective0    perspective;
        
        //! Our scene (ie, renders, lights, etc)
        Scene0          scene;
    
        //! Default constructor
        Scene3DWidget0();
        
        //! Default destructor
        virtual ~Scene3DWidget0();
    
        //! Vulkan recording override
        virtual void    vulkan(ViContext&) override;

        //! Pre-record (ie, for textures, UBOS)
        virtual void    prerecord(ViContext&) override;
        
        //! Adds a new thing to the scene (helper)
        void    add_thing(RenderedPtr);
        
        //! Sets the camera for us (helper)
        void    set_camera(CameraCPtr);
        
        static void init_info();
    };
}
