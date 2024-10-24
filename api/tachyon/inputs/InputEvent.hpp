////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>

namespace yq::tachyon {
    class InputEventInfo : public EventInfo {
    public:
        //template <typename C> class Writer;

        InputEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };
    
    class Viewer;
    class Widget;


    /*! \brief Input event 
    
        "Input" event is externally generated, comes from the 
        user/operating-system (or a fast response to it)
    */
    class InputEvent : public Event {
        YQ_OBJECT_INFO(InputEventInfo)
        YQ_OBJECT_DECLARE(InputEvent, Event)
    public:
    
        struct Param : public Event::Param {
            Viewer*     viewer = nullptr;
            Widget*     widget = nullptr;
        };
    
        //  EVENT TODO
    
        virtual ~InputEvent();
        
        //! Viewer (note, for some events, this might be NULL)
        Viewer*     viewer() const { return m_viewer; }
        
        //! Widget (note, for some events, this might be NULL)
        Widget*     widget() const { return m_widget; }
        
    protected:
        InputEvent(const Param&);
    private:
        Viewer* m_viewer;
        Widget* m_widget;
    };
    
    #if 0

    /*! \brief Writer of event information
    */
    template <typename C>
    class InputEventInfo::Writer : public EventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(InputEventInfo* keyboardInputInfo) : EventInfo::Writer<C>(keyboardInputInfo), m_meta(keyboardInputInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(InputEventInfo& keyboardInputInfo) : Writer(&keyboardInputInfo)
        {
        }

    private:
        InputEventInfo* m_meta;
    };
    
    #endif
}
