////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Object.hpp>
#include <yq-toolbox/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {

    class EventInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        EventInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    /*! \brief Something happens
    
        An event is something that happens/commanded (ie, inputs, triggers, windows, etc)
    */
    class Event : public Object {
        YQ_OBJECT_INFO(EventInfo)
        YQ_OBJECT_DECLARE(Event, Object)
    public:
    
        //  EVENT TODO
    
        Event();
        virtual ~Event();
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class EventInfo::Writer : public ObjectInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(EventInfo* eventInfo) : ObjectInfo::Writer<C>(eventInfo), m_meta(eventInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(EventInfo& eventInfo) : Writer(&eventInfo)
        {
        }

    private:
        EventInfo* m_meta;
    };

}
