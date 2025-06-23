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

class SceneRemoveEvent : public EditorEvent {
    YQ_OBJECT_DECLARE(SceneRemoveEvent, EditorEvent)
public:
    SceneRemoveEvent(const Header&, const std::set<SceneID>&);
    SceneRemoveEvent(const Header&, std::set<SceneID>&&);
    SceneRemoveEvent(const SceneRemoveEvent&, const Header&);
    ~SceneRemoveEvent();
    
    PostCPtr    clone(rebind_k, const Header&) const override;

    const std::set<SceneID>&        scenes() const { return m_scenes; }
    static void init_info();
private:
    std::set<SceneID>        m_scenes;
};
