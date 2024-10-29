////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>

namespace yq::tachyon {
    class InputEventInfo : public post::EventInfo {
    public:
        InputEventInfo(std::string_view zName, const post::EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };
    
    class Viewer;

    /*! \brief Input event 
    
        "Input" event is externally generated, comes from the 
        user/operating-system (or a fast response to it)
    */
    class InputEvent : public post::Event {
        YQ_OBJECT_INFO(InputEventInfo)
        YQ_OBJECT_DECLARE(InputEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
            Viewer*     viewer = nullptr;
        };
    
        //  EVENT TODO
    
        virtual ~InputEvent();
        
        //! Viewer (note, for some events, this might be NULL)
        Viewer*     viewer() const { return m_viewer; }
        
    protected:
        InputEvent(const Param&);

    private:
        Viewer* m_viewer;
    };
}
