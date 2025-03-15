////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yt/ui/Widget.hpp>
#include <yt/typedef/widget4.hpp>
#include <yq/shape/AxBox4.hpp>

namespace yq::tachyon {
    
    class Widget⁴Info : public WidgetInfo {
    public:
        template <typename> class Writer;
        
        Widget⁴Info(std::string_view, WidgetInfo&, const std::source_location& sl = std::source_location::current());
    };

    class Widget⁴ : public Widget {
        YQ_TACHYON_INFO(Widget⁴Info);
        YQ_TACHYON_SNAP(Widget⁴Snap);
        YQ_TACHYON_DATA(Widget⁴Data);
        YQ_TACHYON_DECLARE(Widget⁴, Widget)
    public:

        const AxBox4D& aabb() const { return m_aabb; }
        Widget⁴ID   id() const { return Widget⁴ID(UniqueID::id()); }
        void            set_aabb(const AxBox4D&);

        static void init_info();
        
    protected:
        Widget⁴();
        ~Widget⁴();

        void snap(Widget⁴Snap&) const;

    private:
        AxBox4D     m_aabb = IDENTITY;
    };

}
