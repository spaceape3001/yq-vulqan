////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Reply.hpp>
#include <tachyon/api/PostMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of event information
    */
    template <typename C>
    class ReplyInfo::Writer : public PostMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(ReplyInfo* pInfo) : PostMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(ReplyInfo& pInfo) : Writer(&pInfo)
        {
        }

    private:
        ReplyInfo* m_meta;
    };
}
