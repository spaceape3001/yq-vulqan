////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Widget.hpp>
#include <tachyon/scene/Perspective.hpp>
#include <tachyon/scene/Scene.hpp>

namespace yq::tachyon {
    class Scene3D : public Widget {
        YQ_OBJECT_DECLARE(Scene3D, Widget)
    public:
    
        Perspective     perspective;
        Scene           scene;
    
        Scene3D();
        virtual ~Scene3D();
    
        virtual void    vulkan_(ViContext&) override;

        virtual void    prerecord(ViContext&) override;
        
        void    add_thing(RenderedPtr);
        void    set_camera(CameraCPtr);
    };
}
