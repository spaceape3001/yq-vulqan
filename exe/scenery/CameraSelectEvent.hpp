////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/EditorEvent.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/typedef/camera.hpp>

using namespace yq;
using namespace yq::tachyon;

class CameraSelectEvent : public EditorEvent {
    YQ_OBJECT_DECLARE(CameraSelectEvent, EditorEvent)
public:
    CameraSelectEvent(const Header&, CameraID);
    CameraSelectEvent(const CameraSelectEvent&, const Header&);
    ~CameraSelectEvent();
    
    PostCPtr    clone(rebind_k, const Header&) const override;

    CameraID        camera() const { return m_camera; }
    static void init_info();
private:
    CameraID        m_camera;
};
