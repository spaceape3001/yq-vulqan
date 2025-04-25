////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>
#include <tachyon/typedef/camera.hpp>
#include <tachyon/typedef/scene.hpp>

namespace yq::tachyon {
    class CompositeWidget : public Widget {
        YQ_WIDGET_DECLARE(CompositeWidget, Widget)
    public:
    
        CompositeWidget();
        ~CompositeWidget();
        
        int   add_layer(CameraID, SceneID);

        virtual void    vulkan(ViContext&) override;
        virtual void    prerecord(ViContext&) override;

        static void init_info();
        
    private:
        struct Layer {
            CameraID    camera;
            SceneID     scene;
        };
        
        std::vector<Layer>  m_layers;
        
    };
}
