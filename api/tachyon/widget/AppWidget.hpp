////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Widget.hpp>

namespace yq::tachyon {

    struct AppMenu;
    struct AppItem;

    class AppWidgetInfo : public WidgetInfo {
    public:
        template <typename C>  struct Writer;

        AppWidgetInfo(std::string_view zName, WidgetInfo& base, const std::source_location& sl=std::source_location::current());

        //! TRUE if this has/needs a menu bar
        bool        menu_bar() const { return has(Flag::MENU_BAR); }

    private:
        using ItemGenerator = std::function<AppItem()>;
        std::vector<ItemGenerator> m_items;
    };

    /*! \brief A typical "main" imgui-based widget for an application
    
        This would be a standard top-level "window" with menubars, docks,
        a toolbar, a status bar, etc...
    */
    class AppWidget : public Widget {
        YQ_WIDGET_INFO(AppWidgetInfo)
        YQ_WIDGET_DECLARE(AppWidget, Widget)
    public:
    
        static void init_info();
        
        AppWidget();
        ~AppWidget();
        
        virtual bool        menubar(enabled_k) const { return false; }
        virtual unsigned    menubar(height_k) const { return 0; }
        virtual unsigned    menubar(height_k, ViContext&) const;
        virtual void        menubar(ViContext&){}

        virtual bool        statusbar(enabled_k) const { return false; }
        virtual unsigned    statusbar(height_k) const { return 0; }
        virtual unsigned    statusbar(height_k, ViContext&) const;
        virtual void        statusbar(ViContext&){}
        
        virtual void        content(ViContext&){}
        virtual void        imgui(ViContext&) override;
        
        struct Menu;
        struct MenuItem;
       
    protected:
        //  Action/menus
        
        
    private:
        //  menus
        std::vector<AppItem*>   m_items;
        std::vector<AppItem*>   m_menuBar;
    };
}
