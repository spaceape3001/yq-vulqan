////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Request.hpp>
#include <tachyon/api/PostMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of event information
    */
    template <typename C>
    class RequestInfo::Writer : public PostMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(RequestInfo* reqInfo) : PostMeta::Writer<C>(reqInfo), m_meta(reqInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(RequestInfo& reqInfo) : Writer(&reqInfo)
        {
        }

    private:
        RequestInfo* m_meta;
    };
}
