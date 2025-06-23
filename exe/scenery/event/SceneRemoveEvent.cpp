////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneRemoveEvent.hpp"
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(SceneRemoveEvent)

SceneRemoveEvent::SceneRemoveEvent(const Header& h, const std::set<SceneID>& c) : EditorEvent(h), m_scenes(c)
{
}

SceneRemoveEvent::SceneRemoveEvent(const Header& h, std::set<SceneID>&& c) : EditorEvent(h), m_scenes(std::move(c))
{
}

SceneRemoveEvent::SceneRemoveEvent(const SceneRemoveEvent&cp, const Header&h) : 
    EditorEvent(cp, h), m_scenes(cp.m_scenes)
{
}

SceneRemoveEvent::~SceneRemoveEvent()
{
}


PostCPtr    SceneRemoveEvent::clone(rebind_k, const Header&h) const 
{
    return new SceneRemoveEvent(*this, h);
}

void SceneRemoveEvent::init_info()
{
    auto w = writer<SceneRemoveEvent>();
    w.description("Scene Removeion Event");
}

