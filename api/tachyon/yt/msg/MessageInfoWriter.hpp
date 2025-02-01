////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Message.hpp>
#include <yt/msg/PostInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of event information
    */
    template <typename C>
    class MessageInfo::Writer : public PostInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(MessageInfo* msgInfo) : PostInfo::Writer<C>(msgInfo), m_meta(msgInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(MessageInfo& msgInfo) : Writer(&msgInfo)
        {
        }

    private:
        MessageInfo* m_meta;
    };
}
