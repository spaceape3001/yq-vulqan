////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QCameraLL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/CameraEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraEvent)

namespace yq::tachyon {
    CameraEvent::CameraEvent(const Header& h) : Event(h)
    {
    }
    
    CameraEvent::CameraEvent(const CameraEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    CameraEvent::~CameraEvent()
    {
    }
    
    void CameraEvent::init_info()
    {
        auto w = writer<CameraEvent>();
        w.abstract();
        w.description("Camera Event");
    }
}
