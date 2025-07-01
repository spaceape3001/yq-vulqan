////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Event.hpp>
#include <tachyon/api/PostMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of event information
    */
    template <typename C>
    class EventInfo::Writer : public PostMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(EventInfo* eventInfo) : PostMeta::Writer<C>(eventInfo), m_meta(eventInfo)
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
