////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Trigger.hpp>
#include <yq/tachyon/api/DelegateMetaWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class TriggerMeta::Writer : public DelegateMeta::Writer<C> {
    public:
    
        Writer(TriggerMeta* pInfo) : DelegateMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(TriggerMeta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        TriggerMeta* m_meta;
    };
}
