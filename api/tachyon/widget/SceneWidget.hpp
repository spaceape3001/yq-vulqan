////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <tachyon/api/Widget.hpp>
#include <tachyon/typedef/camera.hpp>
#include <tachyon/typedef/scene.hpp>
#include <tachyon/typedef/push.hpp>
#include <tachyon/typedef/vi_rendered.hpp>
#include <yq/container/BasicBuffer.hpp>

namespace yq::tachyon {
    class SceneWidget : public Widget {
        YQ_TACHYON_DECLARE(SceneWidget, Widget)
    public:
    
        static void init_info();
    
        SceneWidget();
        ~SceneWidget();
        
        using Widget::id;

        CameraID    id(camera_k) const;
        SceneID     id(scene_k) const;

        virtual void    prerecord(ViContext&) override;
    
        void    set_camera(CameraID);
        void    set_scene(SceneID);
    
    private:
        void    _prerecord(ViContext&);
        using Widget::prerecord;

        TypedID                 m_camera;
        TypedID                 m_scene;
        std::optional<RGB3F>    m_background;
        Tristate                m_wireframe     = Tristate::INHERIT;
        RGBA4F                  m_gamma     = { 1., 1., 1., 1. };
    };
}

