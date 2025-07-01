////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/EditorEvent.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/typedef/controller.hpp>

using namespace yq;
using namespace yq::tachyon;

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
