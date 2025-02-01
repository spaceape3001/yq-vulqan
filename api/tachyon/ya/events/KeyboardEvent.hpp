////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/InputEvent.hpp>

namespace yq::tachyon {
    class Window;
    class Viewer;

    class KeyboardEventInfo : public InputEventInfo {
    public:
        KeyboardEventInfo(std::string_view zName, InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class KeyboardEvent : public InputEvent {
        YQ_OBJECT_INFO(KeyboardEventInfo)
        YQ_OBJECT_DECLARE(KeyboardEvent, InputEvent)
        
        template <typename> friend class Ref;
    public:
    
        struct Param : public InputEvent::Param {
        };

        static void init_info();

    protected:
        KeyboardEvent(WindowID, const Param& p);
        KeyboardEvent(Window*, const Param& p);
        virtual ~KeyboardEvent();
    };
}
