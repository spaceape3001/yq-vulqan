////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/InputEvent.hpp>

namespace yq::tachyon {
    class Window;
    class Viewer;

    class KeyboardEventInfo : public InputEventInfo {
    public:
        KeyboardEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class KeyboardEvent : public InputEvent {
        YQ_OBJECT_INFO(KeyboardEventInfo)
        YQ_OBJECT_DECLARE(KeyboardEvent, InputEvent)
        
        template <typename> friend class Ref;
    public:
    
        struct Param : public InputEvent::Param {
        };

    protected:
        KeyboardEvent(const Param& p);
        virtual ~KeyboardEvent();
    };
}
