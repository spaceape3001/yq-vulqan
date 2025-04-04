////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>
#include <yt/keywords.hpp>
#include <yt/typedef/widget.hpp>

namespace yq::tachyon {
    class WidgetInfo;
    class Widget;
    class UIElement;
    class UIItems;
    
    class UIWriter {
    public:
    
        UIWriter();
        UIWriter(Widget&);
        UIWriter(WidgetInfo&);
        UIWriter(UIItems&);
        ~UIWriter();
        
        UIWriter(const UIWriter&);
        UIWriter(UIWriter&&);
        UIWriter& operator=(const UIWriter&);
        UIWriter& operator=(UIWriter&&);

        UIWriter    menu(std::string_view);

        UIWriter    menubar();
        UIWriter    menubar(main_k);
        
        void        menuitem(std::string_view, std::string_view scut="");
        
        void        menuitem(dialog_k, std::string_view, std::string_view scut=""); //< TBD
        void        menuitem(dock_k, std::string_view, std::string_view scut=""); //< TBD
        void        menuitem(open_k, std::string_view, std::string_view scut=""); //< TBD
        void        menuitem(widget_k, std::string_view, std::string_view scut=""); //< TBD
        
        UIWriter    right(align_k);
        
        UIWriter    operator<<(UIElement*);

    protected:
        bool        add(UIElement*);

    private:
        std::variant<std::monostate, UIItems*, Widget*, WidgetInfo*>     m_owner;
    };
}
