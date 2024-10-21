////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class Window;
    class Viewer;

    class CursorEventInfo : public InputEventInfo {
    public:
        CursorEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class CursorEvent : public InputEvent {
        YQ_OBJECT_INFO(CursorEventInfo)
        YQ_OBJECT_DECLARE(CursorEvent, InputEvent)
    public:

        struct Param : public InputEvent::Param {
            Vector2D    position;
        };

        virtual ~CursorEvent();
        
        const Vector2D& position() const { return m_position; }
    
    protected:
        CursorEvent(const Param&);

    private:
        Vector2D    m_position;
    };
}
