////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ControllerSelectEvent.hpp"
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(ControllerSelectEvent)

ControllerSelectEvent::ControllerSelectEvent(const Header& h, ControllerID c) : EditorEvent(h), m_controller(c)
{
}

ControllerSelectEvent::ControllerSelectEvent(const ControllerSelectEvent&cp, const Header&h) : 
    EditorEvent(cp, h), m_controller(cp.m_controller)
{
}

ControllerSelectEvent::~ControllerSelectEvent()
{
}


PostCPtr    ControllerSelectEvent::clone(rebind_k, const Header&h) const 
{
    return new ControllerSelectEvent(*this, h);
}

void ControllerSelectEvent::init_info()
{
    auto w = writer<ControllerSelectEvent>();
    w.description("Controller Selection Event");
}

