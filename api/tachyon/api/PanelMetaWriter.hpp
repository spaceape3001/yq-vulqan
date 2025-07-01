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
    class PanelMeta::Writer : public WidgetMeta::Writer<C> {
    public:
    
        Writer(PanelMeta* panelInfo) : WidgetMeta::Writer<C>(panelInfo), m_meta(panelInfo)
        {
        }
        
        Writer(PanelMeta& panelInfo) : Writer(&panelInfo)
        {
        }
        
    private:
        PanelMeta* m_meta;
        
    };
}
