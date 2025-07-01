////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LightSelectEvent.hpp"
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(LightSelectEvent)

LightSelectEvent::LightSelectEvent(const Header& h, LightID c) : EditorEvent(h), m_light(c)
{
}

LightSelectEvent::LightSelectEvent(const LightSelectEvent&cp, const Header&h) : 
    EditorEvent(cp, h), m_light(cp.m_light)
{
}

LightSelectEvent::~LightSelectEvent()
{
}


PostCPtr    LightSelectEvent::clone(rebind_k, const Header&h) const 
{
    return new LightSelectEvent(*this, h);
}

void LightSelectEvent::init_info()
{
    auto w = writer<LightSelectEvent>();
    w.description("Light Selection Event");
}

