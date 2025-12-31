////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/EditorEvent.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/scene.hpp>

namespace yq::tachyon {

    class SceneRemoveEvent : public EditorEvent {
        YQ_OBJECT_DECLARE(SceneRemoveEvent, EditorEvent)
    public:
        SceneRemoveEvent(const Header&, const std::set<SceneID>&);
        SceneRemoveEvent(const Header&, std::set<SceneID>&&);
        SceneRemoveEvent(const SceneRemoveEvent&, const Header&);
        ~SceneRemoveEvent();
        
        PostCPtr    clone(rebind_k, const Header&) const override;

        const std::set<SceneID>&        scenes() const { return m_scenes; }
        static void init_meta();
    private:
        std::set<SceneID>        m_scenes;
    };
}
