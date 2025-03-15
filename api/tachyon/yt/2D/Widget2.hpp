////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yt/ui/Widget.hpp>
#include <yt/typedef/widget2.hpp>
#include <yq/shape/AxBox2.hpp>

namespace yq::tachyon {
    
    class SetAABB²;
    
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

        Widget²ID       id() const { return Widget²ID(UniqueID::id()); }
        const AxBox2D&  aabb() const { return m_aabb; }
        void            set_aabb(const AxBox2D&);

        static void init_info();
        
    protected:
        Widget²();
        ~Widget²();
        
        void snap(Widget²Snap&) const;
        
        //! Sub-class notification when the bounds changed
        virtual void  aabb_changed(){}
        
    private:
        AxBox2D     m_aabb = IDENTITY;

        void on_set_aabb(const SetAABB²&);
    };

}
