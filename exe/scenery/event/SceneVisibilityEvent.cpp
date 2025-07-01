////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneVisibilityEvent.hpp"
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(SceneVisibilityEvent)

SceneVisibilityEvent::SceneVisibilityEvent(const Header& h, SceneID c) : EditorEvent(h), m_scene(c)
{
}

SceneVisibilityEvent::SceneVisibilityEvent(const SceneVisibilityEvent&cp, const Header&h) : 
    EditorEvent(cp, h), m_scene(cp.m_scene)
{
}

SceneVisibilityEvent::~SceneVisibilityEvent()
{
}


PostCPtr    SceneVisibilityEvent::clone(rebind_k, const Header&h) const 
{
    return new SceneVisibilityEvent(*this, h);
}

void SceneVisibilityEvent::init_meta()
{
    auto w = writer<SceneVisibilityEvent>();
    w.description("Scene Visibilityion Event");
}

