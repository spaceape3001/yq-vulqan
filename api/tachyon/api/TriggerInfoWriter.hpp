////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Trigger.hpp>
#include <tachyon/api/DelegateInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class TriggerInfo::Writer : public DelegateInfo::Writer<C> {
    public:
    
        Writer(TriggerInfo* pInfo) : DelegateInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(TriggerInfo& pInfo) : Writer(&pInfo)
        {
        }

    private:
        TriggerInfo* m_meta;
    };
}
