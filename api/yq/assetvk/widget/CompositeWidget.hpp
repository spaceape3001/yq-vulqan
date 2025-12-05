////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/enum/RenderMode.hpp>

namespace yq::tachyon {
    class CompositeWidget : public Widget {
        YQ_WIDGET_DECLARE(CompositeWidget, Widget)
    public:
    
        struct Param : public Widget::Param {};
    
        CompositeWidget();
        CompositeWidget(const Param&);
        ~CompositeWidget();

        virtual void    prerecord(ViContext&) override;

        static void init_meta();
        
    protected:
        using camera_tweaks_t   = std::vector<CameraTweakCPtr>;
    
        struct CLayer {
            CameraID        camera;
            SceneID         scene;
            camera_tweaks_t tweaks;  //< Set for tweaking the camera
            RGBA4F          gamma       = { 1., 1., 1., 1. };
            RenderMode      renderMode  = RenderMode::Simple;
        };
    
        std::vector<CLayer> m_layers;
        RGBA4F              m_bgcolor       = { 0., 0., 0., 1. };

        void    _prerecord(ViContext&, const CLayer&);
        using Widget::prerecord;
    };
}
