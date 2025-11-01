////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {

    /*! \brief Mini information
    */
    class PanelMeta : public WidgetMeta {
    public:
        template <typename C>  struct Writer;
        
        PanelMeta(std::string_view, WidgetMeta&, const std::source_location& sl = std::source_location::current());
    };

    /*! "Panel" widgets
    
        These are larger widgets that can float around, generally have a mission.
    */
    class Panel : public Widget {
        YQ_TACHYON_META(PanelMeta)
        YQ_TACHYON_DECLARE(Panel, Widget)
    public:
        Panel();
        virtual ~Panel();
        static void init_meta();
    };
}
