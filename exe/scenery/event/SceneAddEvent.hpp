////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/EditorEvent.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/typedef/scene.hpp>

using namespace yq;
using namespace yq::tachyon;

class SceneAddEvent : public EditorEvent {
    YQ_OBJECT_DECLARE(SceneAddEvent, EditorEvent)
public:
    SceneAddEvent(const Header&, const std::set<SceneID>&);
    SceneAddEvent(const Header&, std::set<SceneID>&&);
    SceneAddEvent(const SceneAddEvent&, const Header&);
    ~SceneAddEvent();
    
    PostCPtr    clone(rebind_k, const Header&) const override;

    const std::set<SceneID>&        scenes() const { return m_scenes; }
    static void init_info();
private:
    std::set<SceneID>        m_scenes;
};
