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
        UIWriter(UIElement&);
        ~UIWriter();
        
        UIWriter(const UIWriter&);
        UIWriter(UIWriter&&);
        UIWriter& operator=(const UIWriter&);
        UIWriter& operator=(UIWriter&&);

        UIWriter    center(align_k);
        
        UIWriter    label(std::string_view);

        UIWriter    menu(std::string_view);

        UIWriter    menubar();
        UIWriter    menubar(main_k);
        
        UIWriter    menuitem(std::string_view, std::string_view scut="");
        
        UIWriter    menuitem(dialog_k, std::string_view, std::string_view scut=""); //< TBD
        UIWriter    menuitem(dock_k, std::string_view, std::string_view scut=""); //< TBD
        UIWriter    menuitem(open_k, std::string_view, std::string_view scut=""); //< TBD
        UIWriter    menuitem(widget_k, std::string_view, std::string_view scut=""); //< TBD
        
        UIWriter    right(align_k);
        
        UIWriter    operator<<(UIElement*);
        
        bool        addable() const;

    protected:
        bool        add(UIElement*);

    private:
        std::variant<std::monostate, UIItems*, UIElement*, Widget*, WidgetInfo*>     m_owner;
    };
}
