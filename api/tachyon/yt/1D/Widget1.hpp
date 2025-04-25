////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yt/ui/Widget.hpp>
#include <tachyon/typedef/widget1.hpp>
#include <yq/shape/AxBox1.hpp>

namespace yq::tachyon {
    class SetAABB¹;
    
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

        const AxBox1D&  aabb() const { return m_aabb; }
        Widget¹ID       id() const { return Widget¹ID(UniqueID::id()); }
        void            set_aabb(const AxBox1D&);

        static void init_info();
        
    protected:
        Widget¹();
        ~Widget¹();

        void snap(Widget¹Snap&) const;

        //! Sub-class notification when the bounds changed
        virtual void  aabb_changed(){}

    private:
        AxBox1D     m_aabb = IDENTITY;

        void on_set_aabb(const SetAABB¹&);
    };

}
