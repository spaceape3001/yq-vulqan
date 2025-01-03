////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/WindowEvent.hpp>

namespace yq::tachyon {
    class WindowTitleEvent : public WindowEvent {
        YQ_OBJECT_DECLARE(WindowTitleEvent, WindowEvent)
    public:
    
        struct Param : public WindowEvent::Param {
        };
    
        WindowTitleEvent(Window*, std::string_view, const Param& p = {});
        virtual ~WindowTitleEvent();
        
        static void init_info();
        
        const std::string&  title() const { return m_title; }
    private:
        std::string     m_title;
    };
}
