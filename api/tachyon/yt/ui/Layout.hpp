////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Delegate.hpp>
#include <yt/typedef/widget.hpp>
#include <yt/api/ID.hpp>

namespace yq::tachyon {
    class Context;

    class LayoutInfo : public DelegateInfo {
    public:
        template <typename C> class Writer;
        LayoutInfo(std::string_view, DelegateInfo&, const std::source_location& sl = std::source_location::current());
    };

    class Layout : public Delegate {
        YQ_OBJECT_INFO(LayoutInfo)
        YQ_OBJECT_DECLARE(Layout, Delegate)
    public:
    
        struct TickAPI {
            const Context&                          context;
            const WidgetSnap*                       widget      = nullptr;
            std::vector<const WidgetSnap*>          children;
            std::set<WidgetID>                      added, removed, changed;
        };
    
        static void init_info();
        
        WidgetID        widget() const { return m_widget; }
        
        virtual void tick(const TickAPI&) = 0;
    
    protected:
        Layout();
        virtual ~Layout();
    
    private:
        friend class Widget;
        
        void    set_widget(WidgetID);
        void    tick(Widget&, const Context&);
    
        Layout(const Layout&) = delete;
        Layout(Layout&&) = delete;
        Layout& operator=(const Layout&) = delete;
        Layout& operator=(Layout&&) = delete;
        
        WidgetID                        m_widget;
        Widget*                         m_callback  = nullptr;
        std::map<WidgetID, uint64_t>    m_revisions;
    };
}
