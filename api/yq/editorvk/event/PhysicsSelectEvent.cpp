////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PhysicsSelectEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PhysicsSelectEvent)

namespace yq::tachyon {

    PhysicsSelectEvent::PhysicsSelectEvent(const Header& h, PhysicsID c) : EditorEvent(h), m_physics(c)
    {
    }

    PhysicsSelectEvent::PhysicsSelectEvent(const PhysicsSelectEvent&cp, const Header&h) : 
        EditorEvent(cp, h), m_physics(cp.m_physics)
    {
    }

    PhysicsSelectEvent::~PhysicsSelectEvent()
    {
    }


    PostCPtr    PhysicsSelectEvent::clone(rebind_k, const Header&h) const 
    {
        return new PhysicsSelectEvent(*this, h);
    }

    void PhysicsSelectEvent::init_meta()
    {
        auto w = writer<PhysicsSelectEvent>();
        w.description("Physics Selection Event");
    }

}
