////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QCameraLL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Event.hpp>
#include <tachyon/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class CameraEvent : public Event {
        YQ_OBJECT_DECLARE(CameraEvent, Event)
    public:
    
        static void init_info();

    protected:
        CameraEvent(const Header&);
        CameraEvent(const CameraEvent&, const Header&);
        ~CameraEvent();
    
    private:
        CameraEvent(const CameraEvent&) = delete;
        CameraEvent(CameraEvent&&) = delete;
        CameraEvent& operator=(const CameraEvent&) = delete;
        CameraEvent& operator=(CameraEvent&&) = delete;
    };
}
