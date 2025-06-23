////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneSelectEvent.hpp"
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(SceneSelectEvent)

SceneSelectEvent::SceneSelectEvent(const Header& h, SceneID c) : EditorEvent(h), m_scene(c)
{
}

SceneSelectEvent::SceneSelectEvent(const SceneSelectEvent&cp, const Header&h) : 
    EditorEvent(cp, h), m_scene(cp.m_scene)
{
}

SceneSelectEvent::~SceneSelectEvent()
{
}


PostCPtr    SceneSelectEvent::clone(rebind_k, const Header&h) const 
{
    return new SceneSelectEvent(*this, h);
}

void SceneSelectEvent::init_info()
{
    auto w = writer<SceneSelectEvent>();
    w.description("Scene Selection Event");
}

