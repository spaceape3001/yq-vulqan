////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CameraEvent)

namespace yq::tachyon {
    CameraEventInfo::CameraEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl) :
        post::EventInfo(zName, base, sl)
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    CameraEvent::CameraEvent(Camera* v, const Param& p) : post::Event(p), CameraBind(v)
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
