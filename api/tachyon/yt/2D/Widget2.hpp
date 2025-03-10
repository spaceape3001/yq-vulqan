////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yt/ui/Widget.hpp>
#include <yt/typedef/widget2.hpp>

namespace yq::tachyon {
    
    class Widget²Info : public WidgetInfo {
    public:
        template <typename> class Writer;
        
        Widget²Info(std::string_view, WidgetInfo&, const std::source_location& sl = std::source_location::current());
    };

    class Widget² : public Widget {
        YQ_TACHYON_INFO(Widget²Info);
        YQ_TACHYON_SNAP(Widget²Snap);
        YQ_TACHYON_DATA(Widget²Data);
        YQ_TACHYON_DECLARE(Widget², Widget)
    public:

        Widget²ID   id() const { return Widget²ID(UniqueID::id()); }

        static void init_info();
        
    protected:
        Widget²();
        ~Widget²();
    };

}
