////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Delegate.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class DelegateMeta::Writer : public ObjectInfo::Writer<C> {
    public:
    
        Writer(DelegateMeta* pInfo) : ObjectInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(DelegateMeta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        DelegateMeta* m_meta;
    };
}
