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

    class SceneAddEvent : public EditorEvent {
        YQ_OBJECT_DECLARE(SceneAddEvent, EditorEvent)
    public:
        SceneAddEvent(const Header&, const std::set<SceneID>&);
        SceneAddEvent(const Header&, std::set<SceneID>&&);
        SceneAddEvent(const SceneAddEvent&, const Header&);
        ~SceneAddEvent();
        
        PostCPtr    clone(rebind_k, const Header&) const override;

        const std::set<SceneID>&        scenes() const { return m_scenes; }
        static void init_meta();
    private:
        std::set<SceneID>        m_scenes;
    };
}
