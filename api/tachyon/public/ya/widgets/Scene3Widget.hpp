////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/typedef/camera3.hpp>
#include <yt/typedef/rendered3.hpp>
#include <yt/typedef/scene3.hpp>
#include <yv/typedef/vi_rendered.hpp>

namespace yq::tachyon {
    class Scene³Widget : public Widget {
        YQ_TACHYON_DECLARE(Scene³Widget, Widget)
    public:
    
        static void init_info();
    
        Scene³Widget();
        ~Scene³Widget();
        
        using Widget::id;
        Camera³ID   id(camera_k) const { return Camera³ID{ m_camera.id }; }
        Scene³ID    id(scene_k) const { return Scene³ID{ m_scene.id }; }

        virtual void    vulkan(ViContext&) override;
        virtual void    prerecord(ViContext&) override;
    
        void    set_camera(Camera³ID);
        void    set_scene(Scene³ID);
    
    private:
        void    _prerecord(ViContext&);

        TypedID                             m_scene;
        TypedID                             m_camera;
        std::optional<RGB3F>                m_background;
        Tristate                            m_wireframe     = Tristate::INHERIT;
        std::vector<ViRenderedPtr>          m_rendereds;    // carried prerecord->vulkan
        Tensor44D                           m_view          = IDENTITY;
        Tensor44D                           m_projection    = IDENTITY;
    };
}

