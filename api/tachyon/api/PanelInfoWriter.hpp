////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Panel.hpp>
#include <tachyon/api/WidgetMetaWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of panel information
    */
    template <typename C>
    class PanelInfo::Writer : public WidgetMeta::Writer<C> {
    public:
    
        Writer(PanelInfo* panelInfo) : WidgetMeta::Writer<C>(panelInfo), m_meta(panelInfo)
        {
        }
        
        Writer(PanelInfo& panelInfo) : Writer(&panelInfo)
        {
        }
        
    private:
        PanelInfo* m_meta;
        
    };
}
