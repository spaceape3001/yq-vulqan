////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneAddEvent.hpp"
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(SceneAddEvent)

SceneAddEvent::SceneAddEvent(const Header& h, const std::set<SceneID>& c) : EditorEvent(h), m_scenes(c)
{
}

SceneAddEvent::SceneAddEvent(const Header& h, std::set<SceneID>&& c) : EditorEvent(h), m_scenes(std::move(c))
{
}

SceneAddEvent::SceneAddEvent(const SceneAddEvent&cp, const Header&h) : 
    EditorEvent(cp, h), m_scenes(cp.m_scenes)
{
}

SceneAddEvent::~SceneAddEvent()
{
}


PostCPtr    SceneAddEvent::clone(rebind_k, const Header&h) const 
{
    return new SceneAddEvent(*this, h);
}

void SceneAddEvent::init_info()
{
    auto w = writer<SceneAddEvent>();
    w.description("Scene Addion Event");
}

