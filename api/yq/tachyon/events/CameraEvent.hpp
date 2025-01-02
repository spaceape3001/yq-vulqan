////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>
#include <yq/tachyon/scene/CameraBind.hpp>

namespace yq::tachyon {
    class Camera;

    class CameraEventInfo : public EventInfo {
    public:
        CameraEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class CameraEvent : public Event, public CameraBind {
        YQ_OBJECT_INFO(CameraEventInfo)
        YQ_OBJECT_DECLARE(CameraEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        CameraEvent(Camera*, const Param& p = {});
        CameraEvent(CameraID, const Param& p = {});
        virtual ~CameraEvent();
        
        static void init_info();
    };
}
