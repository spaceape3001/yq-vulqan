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
#include <yt/typedef/camera.hpp>
#include <yt/typedef/camera3.hpp>
#include <yt/typedef/rendered3.hpp>
#include <yt/typedef/scene3.hpp>
#include <yt/typedef/push.hpp>
#include <yv/typedef/vi_rendered.hpp>
#include <ya/widgets/AbstractSceneWidgetHelper.hpp>
#include <yq/container/BasicBuffer.hpp>

namespace yq::tachyon {
    class Scene³Widget : public Widget, public AbstractSceneWidgetHelper {
        YQ_TACHYON_DECLARE(Scene³Widget, Widget)
    public:
    
        static void init_info();
    
        Scene³Widget();
        ~Scene³Widget();
        
        using Widget::id;
        using AbstractSceneWidgetHelper::id;

        CameraID    id(camera_k) const;
        Camera³ID   id(camera³_k) const;

        virtual void    vulkan(ViContext&) override;
        virtual void    prerecord(ViContext&) override;
    
        void    set_camera(Camera³ID);
        void    set_scene(Scene³ID);
    
    private:
        void    _prerecord(ViContext&);

        struct R {
            ViRenderedPtr   vi;
            PushBuffer      push;
        };

        TypedID             m_camera;
        std::vector<R>      m_rendereds;    // carried prerecord->vulkan
        Tensor44D           m_view          = IDENTITY;
        Tensor44D           m_projection    = IDENTITY;
    };
}

