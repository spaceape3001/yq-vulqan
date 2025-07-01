////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Post.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of event information
    */
    template <typename C>
    class PostMeta::Writer : public ObjectInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(PostMeta* pInfo) : ObjectInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(PostMeta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        PostMeta* m_meta;
    };
}
