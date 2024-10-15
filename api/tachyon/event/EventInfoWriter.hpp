////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/ObjectInfoWriter.hpp>
#include <tachyon/event/Event.hpp>

namespace yq::tachyon {
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
