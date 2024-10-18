////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>

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

        //  EVENT TODO
        
        Viewer*     viewer() const { return m_viewer; }
        Widget*     widget() const { return m_widget; }

        virtual ~CursorEvent();
    
    protected:
        CursorEvent(Viewer* v, Widget*w);

    private:
        Viewer* const   m_viewer;
        Widget* const   m_widget;
    };
}
