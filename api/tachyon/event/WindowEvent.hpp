////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Event.hpp>

namespace yq::tachyon {
    class WindowEvent : public Event {
        YQ_OBJECT_DECLARE(WindowEvent, Event)
    public:
    
        static void init_info();

    protected:
        WindowEvent(const Header&);
        WindowEvent(const WindowEvent&, const Header&);
        virtual ~WindowEvent();
        
        
    private:
        WindowEvent(const WindowEvent&) = delete;
        WindowEvent(WindowEvent&&) = delete;
        WindowEvent& operator=(const WindowEvent&) = delete;
        WindowEvent& operator=(WindowEvent&&) = delete;
    };
}
