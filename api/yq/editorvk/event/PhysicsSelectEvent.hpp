////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/EditorEvent.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/physicsvk/typedef/physics.hpp>

namespace yq::tachyon {

    class PhysicsSelectEvent : public EditorEvent {
        YQ_OBJECT_DECLARE(PhysicsSelectEvent, EditorEvent)
    public:
        PhysicsSelectEvent(const Header&, PhysicsID);
        PhysicsSelectEvent(const PhysicsSelectEvent&, const Header&);
        ~PhysicsSelectEvent();
        
        PostCPtr    clone(rebind_k, const Header&) const override;

        PhysicsID        physics() const { return m_physics; }
        static void init_meta();
    private:
        PhysicsID        m_physics;
    };
}
