////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/Request.hpp>
#include <tachyon/msg/PostInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of event information
    */
    template <typename C>
    class RequestInfo::Writer : public PostInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(RequestInfo* reqInfo) : PostInfo::Writer<C>(reqInfo), m_meta(reqInfo)
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
