////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>

namespace yq::tachyon {
    class CommandInfo : public EventInfo {
    public:
        template <typename C> class Writer;

        CommandInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    /*! \brief Translated event into a command
    
        eg... Joystick up being translated into "pan up"
    */
    class Command : public Event {
        YQ_OBJECT_INFO(CommandInfo)
        YQ_OBJECT_DECLARE(Command, Event)
    public:
    
        //  EVENT TODO
    
        Command();
        virtual ~Command();
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class CommandInfo::Writer : public EventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(CommandInfo* commandInfo) : EventInfo::Writer<C>(commandInfo), m_meta(commandInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(CommandInfo& commandInfo) : Writer(&commandInfo)
        {
        }

    private:
        CommandInfo* m_meta;
    };
}
