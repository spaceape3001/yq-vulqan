////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yt/ui/Widget.hpp>
#include <tachyon/typedef/widget3.hpp>
#include <yq/shape/AxBox3.hpp>

namespace yq::tachyon {
    class SetAABB³;
    
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

        const AxBox3D& aabb() const { return m_aabb; }
        Widget³ID   id() const { return Widget³ID(UniqueID::id()); }
        void            set_aabb(const AxBox3D&);

        static void init_info();
        
    protected:
        Widget³();
        ~Widget³();

        void snap(Widget³Snap&) const;
        //! Sub-class notification when the bounds changed
        virtual void  aabb_changed(){}

    private:
        AxBox3D     m_aabb = IDENTITY;

        void on_set_aabb(const SetAABB³&);
    };

}
