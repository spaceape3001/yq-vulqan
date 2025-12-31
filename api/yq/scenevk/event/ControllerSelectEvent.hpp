////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/EditorEvent.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/controller.hpp>

namespace yq::tachyon {

    class ControllerSelectEvent : public EditorEvent {
        YQ_OBJECT_DECLARE(ControllerSelectEvent, EditorEvent)
    public:
        ControllerSelectEvent(const Header&, ControllerID);
        ControllerSelectEvent(const ControllerSelectEvent&, const Header&);
        ~ControllerSelectEvent();
        
        PostCPtr    clone(rebind_k, const Header&) const override;

        ControllerID        controller() const { return m_controller; }
        static void init_meta();
    private:
        ControllerID        m_controller;
    };
}
