////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/ID.hpp>
#include <yt/typedef/scene.hpp>

namespace yq::tachyon {
    class Scene;

    //! Utiltity to bind a viewer to the whatever...
    class SceneBind {
    public:
        SceneID    scene() const { return m_scene; }
        
    protected:
        SceneBind(SceneID v) : m_scene(v) {}
        SceneBind(const Scene* v);
        virtual ~SceneBind() {}
        
        SceneID const m_scene;
    };
}