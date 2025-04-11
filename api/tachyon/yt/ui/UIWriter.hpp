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
#include <yt/typedef/uimisc.hpp>
#include <yt/enum/UICardinal.hpp>
#include <yt/enum/UIFlags.hpp>
#include <yq/typedef/vector2.hpp>

namespace yq::tachyon {
    class WidgetInfo;
    class Widget;
    class UI;
    class UIElements;
    
    class UIWriter {
    public:
        
        UIWriter();
        UIWriter(Widget&);
        UIWriter(WidgetInfo&);
        UIWriter(UIElements&);
        UIWriter(UI&);
        ~UIWriter();
        
        UIWriter(const UIWriter&);
        UIWriter(UIWriter&&);
        UIWriter& operator=(const UIWriter&);
        UIWriter& operator=(UIWriter&&);

        ////////////////////////////////
        // Informational/Administration
        ////////////////////////////////

        /*! \brief Can we add widgets?
            
            This is True if we're pointing to something that can be added to, like
            a valid widget, widget info, or uielements; false otherwise
        */
        
        bool        addable() const;

        //! Current element being added onto (note may be NULL)
        UI*  element();

        operator UI*();

        /*! Appends to the container
        
            \note This operator takes OWNERSHIP for the pointer
            and may delete it!  (Immediately if addable() is false.)
        */
        UIWriter    operator<<(UI*);


        ////////////////////////////////
        // Element Creation Helpers
        ////////////////////////////////

        UIWriter    button(std::string_view);
        UIWriter    button(std::string_view, const Vector2F& size);

        template <SomePost P>
        UIWriter    button(std::string_view, post_k<P>);

        template <SomePost P>
        UIWriter    button(std::string_view, const Vector2F& size, post_k<P>);

        template <SomeWidget W>
        UIWriter    button(std::string_view, void (W::*)());

        template <SomeWidget W>
        UIWriter    button(std::string_view, const Vector2F& size, void (W::*)());

        //! The contents will be centered (as best as it can do)
        UIWriter    center(align_k);
        
        
        //! The contents within will all be placed same line
        UIWriter    hbox();
        
        UIWriter    label(std::string_view);
        
        //! Call if it's a main window widget
        UIWriter    main(app_k, UIFlags flags={});

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
        
        UIWriter    toolbar(UICardinal, std::string_view kName);
        UIWriter    toolbar(const Vector2F&, std::string_view kName);
        
        UIWriter    window(std::string_view kName={});
        
        
    protected:
        bool        add(UI*);

    private:
        std::variant<std::monostate, UIElements*, UI*, Widget*, WidgetInfo*>     m_owner;
    };
}
