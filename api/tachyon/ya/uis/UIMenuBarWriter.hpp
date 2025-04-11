////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIMenuBar;
    class UIMenuItemWriter;
    
    class UIMenuBarWriter : public UIElementsWriter {
    public:
        UIMenuBarWriter();
        UIMenuBarWriter(UIMenuBar*);
        UIMenuBarWriter(const UIMenuBarWriter&);
        ~UIMenuBarWriter();
        
        UIMenuBar*  element();

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////


        UIMenuItemWriter    menuitem(std::string_view, std::string_view scut="");

        /*! \brief Menu Item that sends the widget a post (ie, command, request, event, etc)
        
            \note This post must be able to take a simple post header
        */
        template <SomePost P>
        UIMenuItemWriter    menuitem(std::string_view, post_k<P>);

        /*! \brief Menu Item that sends the widget a post (ie, command, request, event, etc)
        
            \note This post must be able to take a simple post header
        */
        template <SomePost P>
        UIMenuItemWriter    menuitem(std::string_view, std::string_view scut, post_k<P>);

        /*! \brief Menu item that triggers an on-widget callback
        
            \note Should be the same widget as you're generating a UI for... just saying
        */
        template <SomeWidget W>
        UIMenuItemWriter    menuitem(std::string_view, void (W::*)());
        
        /*! \brief Menu item that triggers an on-widget callback
        
            \note Should be the same widget as you're generating a UI for... just saying
        */
        template <SomeWidget W>
        UIMenuItemWriter    menuitem(std::string_view, std::string_view scut, void (W::*)());
        
        
        UIMenuItemWriter    menuitem(dialog_k, std::string_view, std::string_view scut=""); //< TBD
        UIMenuItemWriter    menuitem(dock_k, std::string_view, std::string_view scut=""); //< TBD
        UIMenuItemWriter    menuitem(open_k, std::string_view, std::string_view scut=""); //< TBD
        UIMenuItemWriter    menuitem(widget_k, std::string_view, std::string_view scut=""); //< TBD
    };
}
