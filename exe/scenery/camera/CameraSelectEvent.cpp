////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraSelectEvent.hpp"
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(CameraSelectEvent)

CameraSelectEvent::CameraSelectEvent(const Header& h, CameraID c) : EditorEvent(h), m_camera(c)
{
}

CameraSelectEvent::CameraSelectEvent(const CameraSelectEvent&cp, const Header&h) : 
    EditorEvent(cp, h), m_camera(cp.m_camera)
{
}

CameraSelectEvent::~CameraSelectEvent()
{
}


PostCPtr    CameraSelectEvent::clone(rebind_k, const Header&h) const 
{
    return new CameraSelectEvent(*this, h);
}

void CameraSelectEvent::init_info()
{
    auto w = writer<CameraSelectEvent>();
    w.description("Camera Selection Event");
}

