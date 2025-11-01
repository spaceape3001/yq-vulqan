////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Delegate.hpp>
#include <yq/meta/ObjectMetaWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class DelegateMeta::Writer : public ObjectMeta::Writer<C> {
    public:
    
        Writer(DelegateMeta* pInfo) : ObjectMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(DelegateMeta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        DelegateMeta* m_meta;
    };
}
