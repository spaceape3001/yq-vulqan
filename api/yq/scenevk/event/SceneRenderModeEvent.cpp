////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneRenderModeEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SceneRenderModeEvent)

namespace yq::tachyon {

    SceneRenderModeEvent::SceneRenderModeEvent(const Header& h, SceneID c, RenderMode rm) : EditorEvent(h), m_scene(c), m_renderMode(rm)
    {
    }

    SceneRenderModeEvent::SceneRenderModeEvent(const SceneRenderModeEvent&cp, const Header&h) : 
        EditorEvent(cp, h), m_scene(cp.m_scene), m_renderMode(cp.m_renderMode)
    {
    }

    SceneRenderModeEvent::~SceneRenderModeEvent()
    {
    }


    PostCPtr    SceneRenderModeEvent::clone(rebind_k, const Header&h) const 
    {
        return new SceneRenderModeEvent(*this, h);
    }

    void SceneRenderModeEvent::init_meta()
    {
        auto w = writer<SceneRenderModeEvent>();
        w.description("Scene RenderModeion Event");
    }

}
