////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>
#include <yq/tachyon/camera/CameraBind.hpp>

namespace yq::tachyon {
    class Camera;

    class CameraEventInfo : public post::EventInfo {
    public:
        CameraEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class CameraEvent : public post::Event, public CameraBind {
        YQ_OBJECT_INFO(CameraEventInfo)
        YQ_OBJECT_DECLARE(CameraEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
        };
    
        CameraEvent(Camera*, const Param& p = {});
        virtual ~CameraEvent();
        
        static void init_info();
    };
}
