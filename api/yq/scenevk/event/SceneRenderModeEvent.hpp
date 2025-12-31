////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/EditorEvent.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/enum/RenderMode.hpp>

namespace yq::tachyon {

    class SceneRenderModeEvent : public EditorEvent {
        YQ_OBJECT_DECLARE(SceneRenderModeEvent, EditorEvent)
    public:
        SceneRenderModeEvent(const Header&, SceneID, RenderMode);
        SceneRenderModeEvent(const SceneRenderModeEvent&, const Header&);
        ~SceneRenderModeEvent();
        
        PostCPtr    clone(rebind_k, const Header&) const override;

        SceneID         scene() const { return m_scene; }
        RenderMode      render_mode() const { return m_renderMode; }
        static void init_meta();
    private:
        SceneID         m_scene;
        RenderMode      m_renderMode;
    };
}
