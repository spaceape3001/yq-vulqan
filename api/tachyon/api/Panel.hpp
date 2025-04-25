////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>

namespace yq::tachyon {

    /*! \brief Mini information
    */
    class PanelInfo : public WidgetInfo {
    public:
        template <typename C>  struct Writer;
        
        PanelInfo(std::string_view, WidgetInfo&, const std::source_location& sl = std::source_location::current());
    };

    /*! "Panel" widgets
    
        These are larger widgets that can float around, generally have a mission.
    */
    class Panel : public Widget {
        YQ_TACHYON_INFO(PanelInfo)
        YQ_TACHYON_DECLARE(Panel, Widget)
    public:
        Panel();
        virtual ~Panel();
        static void init_info();
    };
}
