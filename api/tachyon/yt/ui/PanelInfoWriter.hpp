////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Panel.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

namespace yq::tachyon {
    /*! \brief Writer of panel information
    */
    template <typename C>
    class PanelInfo::Writer : public WidgetInfo::Writer<C> {
    public:
    
        Writer(PanelInfo* panelInfo) : WidgetInfo::Writer<C>(panelInfo), m_meta(panelInfo)
        {
        }
        
        Writer(PanelInfo& panelInfo) : Writer(&panelInfo)
        {
        }
        
    private:
        PanelInfo* m_meta;
        
    };
}
