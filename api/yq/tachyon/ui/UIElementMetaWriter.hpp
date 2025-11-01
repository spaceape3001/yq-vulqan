////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>
#include <yq/meta/ObjectMetaWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class UIElementMeta::Writer : public ObjectMeta::Writer<C> {
    public:
    
        Writer(UIElementMeta* pInfo) : ObjectMeta::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(UIElementMeta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        UIElementMeta* m_meta;
    };
}
