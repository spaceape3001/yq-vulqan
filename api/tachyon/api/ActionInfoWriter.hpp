////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Action.hpp>
#include <tachyon/api/DelegateInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class ActionInfo::Writer : public DelegateInfo::Writer<C> {
    public:
    
        Writer(ActionInfo* pInfo) : DelegateInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(ActionInfo& pInfo) : Writer(&pInfo)
        {
        }

    private:
        ActionInfo* m_meta;
    };
}
