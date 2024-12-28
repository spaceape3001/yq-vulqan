////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Delegate.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class DelegateInfo::Writer : public ObjectInfo::Writer<C> {
    public:
    
        Writer(DelegateInfo* pInfo) : ObjectInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(DelegateInfo& pInfo) : Writer(&pInfo)
        {
        }

    private:
        DelegateInfo* m_meta;
    };
}
