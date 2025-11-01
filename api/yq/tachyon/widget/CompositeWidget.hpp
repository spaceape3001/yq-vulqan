////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>
#include <tachyon/typedef/camera3.hpp>
#include <tachyon/typedef/scene.hpp>

namespace yq::tachyon {
    class CompositeWidget : public Widget {
        YQ_WIDGET_DECLARE(CompositeWidget, Widget)
    public:
    
        CompositeWidget();
        ~CompositeWidget();

        virtual void    prerecord(ViContext&) override;

        static void init_meta();
        
    protected:
        using camera_tweaks_t   = std::vector<CameraTweakCPtr>;
    
        struct CLayer {
            CameraID        camera;
            SceneID         scene;
            camera_tweaks_t tweaks;  //< Set for tweaking the camera
            RGBA4F          gamma     = { 1., 1., 1., 1. };
        };
    
        std::vector<CLayer> m_layers;
        RGBA4F              m_bgcolor   = { 0., 0., 0., 1. };

        void    _prerecord(ViContext&, const CLayer&);
        using Widget::prerecord;
    };
}
