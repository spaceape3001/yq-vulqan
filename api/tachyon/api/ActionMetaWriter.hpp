////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Action.hpp>
#include <tachyon/api/DelegateMetaWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class ActionMeta::Writer : public DelegateMeta::Writer<C> {
    public:
    
        Writer(ActionMeta* pInfo) : DelegateMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(ActionMeta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        ActionMeta* m_meta;
    };
}
