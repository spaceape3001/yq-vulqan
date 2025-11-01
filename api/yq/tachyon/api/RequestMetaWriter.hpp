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
    class RequestMeta::Writer : public PostMeta::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(RequestMeta* reqInfo) : PostMeta::Writer<C>(reqInfo), m_meta(reqInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(RequestMeta& reqInfo) : Writer(&reqInfo)
        {
        }

    private:
        RequestMeta* m_meta;
    };
}
