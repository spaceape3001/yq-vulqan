////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/event/InputEvent.hpp>

namespace yq::tachyon {
    class JoystickEventInfo : public InputEventInfo {
    public:
        template <typename C> class Writer;

        JoystickEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class JoystickEvent : public InputEvent {
        YQ_OBJECT_INFO(JoystickEventInfo)
        YQ_OBJECT_DECLARE(JoystickEvent, InputEvent)
    public:
    
        //  EVENT TODO
    
        JoystickEvent();
        virtual ~JoystickEvent();
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class JoystickEventInfo::Writer : public InputEventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(JoystickEventInfo* joystickInputInfo) : InputEventInfo::Writer<C>(joystickInputInfo), m_meta(joystickInputInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(JoystickEventInfo& joystickInputInfo) : Writer(&joystickInputInfo)
        {
        }

    private:
        JoystickEventInfo* m_meta;
    };
}
