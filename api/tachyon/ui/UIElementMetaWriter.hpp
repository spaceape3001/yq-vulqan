////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class UIElementMeta::Writer : public ObjectInfo::Writer<C> {
    public:
    
        Writer(UIElementMeta* pInfo) : ObjectInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(UIElementMeta& pInfo) : Writer(&pInfo)
        {
        }

    private:
        UIElementMeta* m_meta;
    };
}
