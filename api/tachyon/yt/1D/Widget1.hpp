////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yt/ui/Widget.hpp>
#include <yt/typedef/widget1.hpp>

namespace yq::tachyon {
    
    class Widget¹Info : public WidgetInfo {
    public:
        template <typename> class Writer;
        
        Widget¹Info(std::string_view, WidgetInfo&, const std::source_location& sl = std::source_location::current());
    };

    class Widget¹ : public Widget {
        YQ_TACHYON_INFO(Widget¹Info);
        YQ_TACHYON_SNAP(Widget¹Snap);
        YQ_TACHYON_DATA(Widget¹Data);
        YQ_TACHYON_DECLARE(Widget¹, Widget)
    public:

        Widget¹ID   id() const { return Widget¹ID(UniqueID::id()); }

        static void init_info();
        
    protected:
        Widget¹();
        ~Widget¹();
    };

}
