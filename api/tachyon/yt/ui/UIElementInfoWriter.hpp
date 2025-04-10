////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElement.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    
    /*! \brief Writer of trigger information
    */
    template <typename C>
    class UIElementInfo::Writer : public ObjectInfo::Writer<C> {
    public:
    
        Writer(UIElementInfo* pInfo) : ObjectInfo::Writer<C>(pInfo), m_meta(pInfo)
        {
        }
        
        Writer(UIElementInfo& pInfo) : Writer(&pInfo)
        {
        }

    private:
        UIElementInfo* m_meta;
    };
}
