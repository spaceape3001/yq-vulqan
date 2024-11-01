////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/MouseEvent.hpp>

namespace yq::tachyon {
    class MouseDropEvent : public MouseEvent {
        YQ_OBJECT_DECLARE(MouseDropEvent, MouseEvent)
    public:
    
        struct Param : public MouseEvent::Param {
        };
    
        MouseDropEvent(std::vector<std::string>&&, const Param& p);

        virtual ~MouseDropEvent();
        
        static void init_info();
        
        const std::vector<std::string>& paths() const { return m_paths; }
        
    private:
        const std::vector<std::string>  m_paths;
    };
}

