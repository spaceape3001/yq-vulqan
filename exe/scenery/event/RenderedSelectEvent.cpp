////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RenderedSelectEvent.hpp"
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(RenderedSelectEvent)

RenderedSelectEvent::RenderedSelectEvent(const Header& h, RenderedID c) : EditorEvent(h), m_rendered(c)
{
}

RenderedSelectEvent::RenderedSelectEvent(const RenderedSelectEvent&cp, const Header&h) : 
    EditorEvent(cp, h), m_rendered(cp.m_rendered)
{
}

RenderedSelectEvent::~RenderedSelectEvent()
{
}


PostCPtr    RenderedSelectEvent::clone(rebind_k, const Header&h) const 
{
    return new RenderedSelectEvent(*this, h);
}

void RenderedSelectEvent::init_meta()
{
    auto w = writer<RenderedSelectEvent>();
    w.description("Rendered Selection Event");
}

