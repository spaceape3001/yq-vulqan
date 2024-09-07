////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/event/InputEvent.hpp>

namespace yq::tachyon {
    class KeyboardEventInfo : public InputEventInfo {
    public:
        template <typename C> class Writer;

        KeyboardEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class KeyboardEvent : public InputEvent {
        YQ_OBJECT_INFO(KeyboardEventInfo)
        YQ_OBJECT_DECLARE(KeyboardEvent, InputEvent)
    public:
    
        //  EVENT TODO
    
        KeyboardEvent();
        virtual ~KeyboardEvent();
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class KeyboardEventInfo::Writer : public InputEventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(KeyboardEventInfo* keyboardInputInfo) : InputEventInfo::Writer<C>(keyboardInputInfo), m_meta(keyboardInputInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(KeyboardEventInfo& keyboardInputInfo) : Writer(&keyboardInputInfo)
        {
        }

    private:
        KeyboardEventInfo* m_meta;
    };
}
