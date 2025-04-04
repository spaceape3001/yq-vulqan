////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>
#include <yt/keywords.hpp>

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
        
        UIWriter    operator<<(UIElement*);

    protected:
        bool        add(UIElement*);

    private:
        std::variant<std::monostate, UIItems*, Widget*, WidgetInfo*>     m_owner;
    };
}
