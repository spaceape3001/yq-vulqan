////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yt/ui/Widget.hpp>
#include <yt/typedef/widget3.hpp>
#include <yq/shape/AxBox3.hpp>

namespace yq::tachyon {
    
    class Widget³Info : public WidgetInfo {
    public:
        template <typename> class Writer;
        
        Widget³Info(std::string_view, WidgetInfo&, const std::source_location& sl = std::source_location::current());
    };

    class Widget³ : public Widget {
        YQ_TACHYON_INFO(Widget³Info);
        YQ_TACHYON_SNAP(Widget³Snap);
        YQ_TACHYON_DATA(Widget³Data);
        YQ_TACHYON_DECLARE(Widget³, Widget)
    public:

        Widget³ID   id() const { return Widget³ID(UniqueID::id()); }

        static void init_info();
        
    protected:
        Widget³();
        ~Widget³();

        void snap(Widget³Snap&) const;

    private:
        AxBox3D     m_bounds = IDENTITY;
    };

}
