////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/CameraEvent.hpp>

#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraEvent)

namespace yq::tachyon {
    CameraEventInfo::CameraEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    CameraEvent::CameraEvent(Camera* v, const Param& p) : Event(p), CameraBind(v)
    {
    }
    
    CameraEvent::CameraEvent(CameraID v, const Param& p) : Event(p), CameraBind(v)
    {
    }

    CameraEvent::~CameraEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CameraEvent::init_info()
    {
        auto w = writer<CameraEvent>();
        w.description("Camera event base class");
    }
}
