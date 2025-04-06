////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>
#include <yt/keywords.hpp>
#include <yt/typedef/post.hpp>
#include <yt/typedef/widget.hpp>

namespace yq::tachyon {
    class WidgetInfo;
    class Widget;
    class UIElement;
    class UIElements;
    
    class UIWriter {
    public:
        
        UIWriter();
        UIWriter(Widget&);
        UIWriter(WidgetInfo&);
        UIWriter(UIElements&);
        UIWriter(UIElement&);
        ~UIWriter();
        
        UIWriter(const UIWriter&);
        UIWriter(UIWriter&&);
        UIWriter& operator=(const UIWriter&);
        UIWriter& operator=(UIWriter&&);

        //! The contents will be centered (as best as it can do)
        UIWriter    center(align_k);
        
        //! The contents within will all be placed same line
        UIWriter    hbox();
        
        UIWriter    label(std::string_view);

        UIWriter    menu(std::string_view);

        UIWriter    menubar();
        UIWriter    menubar(main_k);
        
        UIWriter    menuitem(std::string_view, std::string_view scut="");

        /*! \brief Menu Item that sends the widget a post (ie, command, request, event, etc)
        
            \note This post must be able to take a simple post header
        */
        template <SomePost P>
        UIWriter    menuitem(std::string_view, post_k<P>);

        /*! \brief Menu Item that sends the widget a post (ie, command, request, event, etc)
        
            \note This post must be able to take a simple post header
        */
        template <SomePost P>
        UIWriter    menuitem(std::string_view, std::string_view scut, post_k<P>);

        /*! \brief Menu item that triggers an on-widget callback
        
            \note Should be the same widget as you're generating a UI for... just saying
        */
        template <SomeWidget W>
        UIWriter    menuitem(std::string_view, void (W::*)());
        
        /*! \brief Menu item that triggers an on-widget callback
        
            \note Should be the same widget as you're generating a UI for... just saying
        */
        template <SomeWidget W>
        UIWriter    menuitem(std::string_view, std::string_view scut, void (W::*)());
        
        
        UIWriter    menuitem(dialog_k, std::string_view, std::string_view scut=""); //< TBD
        UIWriter    menuitem(dock_k, std::string_view, std::string_view scut=""); //< TBD
        UIWriter    menuitem(open_k, std::string_view, std::string_view scut=""); //< TBD
        UIWriter    menuitem(widget_k, std::string_view, std::string_view scut=""); //< TBD
        
        /*! \brief  Right align the contents
        
            This will right align the contents of it's object (so, it's technically
            an items collection that gets created.
        */
        UIWriter    right(align_k);
        
        UIWriter    operator<<(UIElement*);
        
        bool        addable() const;

    protected:
        bool        add(UIElement*);

    private:
        std::variant<std::monostate, UIElements*, UIElement*, Widget*, WidgetInfo*>     m_owner;
    };
}
