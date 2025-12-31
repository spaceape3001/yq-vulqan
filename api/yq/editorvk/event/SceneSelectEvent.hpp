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
    class SceneSelectEvent : public EditorEvent {
        YQ_OBJECT_DECLARE(SceneSelectEvent, EditorEvent)
    public:
        SceneSelectEvent(const Header&, SceneID);
        SceneSelectEvent(const SceneSelectEvent&, const Header&);
        ~SceneSelectEvent();
        
        PostCPtr    clone(rebind_k, const Header&) const override;

        SceneID        scene() const { return m_scene; }
        static void init_meta();
    private:
        SceneID        m_scene;
    };
}
