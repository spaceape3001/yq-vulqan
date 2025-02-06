////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/tensor/Tensor44.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/typedef/camera3.hpp>
#include <yt/typedef/rendered.hpp>
#include <yt/typedef/rendered3.hpp>
#include <yt/typedef/scene.hpp>
#include <yt/typedef/scene3.hpp>
#include <yt/typedef/push.hpp>
#include <yv/typedef/vi_rendered.hpp>

namespace yq::tachyon {

    struct StdPushData;

    class AbstractSceneWidgetHelper {
    public:
    
        AbstractSceneWidgetHelper();
        ~AbstractSceneWidgetHelper();
    
        SceneID     id(scene_k) const;
        Scene³ID    id(scene³_k) const;
        
    protected:
        TypedID                 m_scene;
        std::optional<RGB3F>    m_background;
        Tristate                m_wireframe     = Tristate::INHERIT;
        
        struct PushContext {
            ViContext&          ctx;
            const Frame&        frame;
            const SceneSnap&    scene;
            double              time;

            glm::dmat4          view, projection;
            Tensor44D           view44;
            Tensor44D           projection44;
            Tensor44D           w2e44;
            glm::dmat4          w2e;
        };
        
        void    _cam_matrix(PushContext&, Camera³ID cam);
        
        void    _cam_matrix(Tensor44D& view, Tensor44D& proj, const Frame&, Camera³ID cam);
        
        
        void    _push(PushBuffer&, const PushContext&, const RenderedSnap&);
        void    _push_mvp(PushBuffer&, const PushContext&, const Rendered³Snap&);
        void    _push_full(PushBuffer&, const PushContext&, const Rendered³Snap&);
        void    _push_view(PushBuffer&, const PushContext&, const RenderedSnap&);
        void    _push_viewproj(PushBuffer&, const PushContext&, const RenderedSnap&);
        void    _push_view64proj(PushBuffer&, const PushContext&, const RenderedSnap&);
        
        RGBA4F          m_gamma     = { 1., 1., 1., 1. };
    };
}
