////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementWriter.hpp>
#include <yq/tachyon/enum/Cardinal.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/uielement.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yq/typedef/size2.hpp>
#include <yq/typedef/vector2.hpp>
#include <yq/tachyon/keywords.hpp>
#include <string_view>
#include <functional>

namespace yq::tachyon {
    class UIElements;
    class Widget;
    class WidgetMeta;
    class UIResourceImageWriter;
    class UIButtonWriter;
    class UICenterAlignWriter;
    class UICheckBoxWriter;
    class UIHBoxLayoutWriter;
    class UIHLineWriter;
    class UIImageWriter;
    class UILineInputWriter;
    class UIMenuWriter;
    class UIMenuBarWriter;
    class UIRightAlignWriter;
    class UISpacerWriter;
    class UITextLabelWriter;
    class UIToolBarWriter;
    class UIVBoxLayoutWriter;
    
    class UIElementsWriter : public UIElementWriter {
    public:
        
        UIElementsWriter();
        UIElementsWriter(Widget*);
        UIElementsWriter(WidgetMeta*);
        UIElementsWriter(UIElements*);
        UIElementsWriter(const UIElementsWriter&);
        ~UIElementsWriter();
        
        UIElements*             element();
        
        /*! Appends a UI element
            \note This routine assumes ownership, may delete the item prior to return.
        */
        template <SomeUIElement U>
        typename U::Writer     operator<<(U* elem)
        {
            if(add(elem)){
                return typename U::Writer(elem);
            } else {
                return typename U::Writer();
            }
        }
        
        //! Creates a new UI element, appending it to the list
        template <SomeUIElement U, typename ... Args>
        typename U::Writer make(Args... args)
        {
            U*  ret = new U(std::forward<Args>(args)...);
            ret->submake();
            if(add(ret)){
                return typename U::Writer(ret);
            } else {
                return typename U::Writer();
            }
        }
        
        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        UIButtonWriter          button(std::string_view);
        UIButtonWriter          button(std::string_view, const Size2F& size);

        //! Creates a callback UI Element
        //!
        //! This allows for a specific bit of your-widget code to be called
        //! at the "right" point in the UI chain
        template <SomeWidget W>
        UIElementWriter         callback(void (W::*)());

        //! The contents will be centered (as best as it can do)
        UICenterAlignWriter     center(align_k);
        
        /*! \brief Create a checkbox that stores its value
        
            This will create a checkbox (UICheckBox_Simple) that will store its
            value internally.  Actions can be attached to get triggered when
            its value is changed.
        */
        UICheckBoxWriter        checkbox(std::string_view, bool value=false);
        UICheckBoxWriter        checkbox(std::string_view, visible_k, UIElement*);
        UICheckBoxWriter        checkbox(std::string_view, visible_k, UIElementWriter&);
        UICheckBoxWriter        checkbox(visible_k, UIElement*);
        UICheckBoxWriter        checkbox(visible_k, UIElementWriter&);

        template <SomeWidget W>
        UICheckBoxWriter        checkbox(std::string_view, bool W::*);

        
        template <SomeUIElement U, SomeWidget W>
        UIElementWriter         generate(std::function<U*(W&)>&&);
        
        UIHBoxLayoutWriter            hbox();
        
        //! The contents within will all be placed same line
        UIHLineWriter           hline();
        
        //! Will display the specified image/texture (using the resource-system)
        UIImageWriter           image(std::string_view);
        
        //! Will display the specified image/texture (using the resource-system) using this FIXED size
        UIImageWriter           image(std::string_view, const Size2F&);
        
        UITextLabelWriter       label(std::string_view);
        
        UILineInputWriter       line_input(std::string_view);

        template <SomeWidget W>
        UILineInputWriter       line_input(std::string_view, void (W::*)());

        template <SomeWidget W>
        UILineInputWriter       line_input(std::string_view, void (W::*)(std::string_view));

        template <SomeWidget W>
        UILineInputWriter       line_input(std::string_view, void (W::*)(const std::string&));

        UIMenuWriter            menu(std::string_view);


        /*! \brief  Right align the contents
        
            This will right align the contents of it's object (so, it's technically
            an items collection that gets created.
        */
        UIRightAlignWriter      right(align_k);
        
        UIElementsWriter        section(std::string_view);
        
        UIElementWriter         separator();
        
        UISpacerWriter          spacer(const Size2F&);
        
        UIVBoxLayoutWriter            vbox();

    protected:
    
        /*! \brief Adds item to the elements
        
            \note This routine assumes ownership, may delete the item 
            prior to return (which is why it'll return false).
        */
        bool    add(UIElement*);
        
    private:
        static UIElements*      attach(Widget*);
        static UIElements*      attach(WidgetMeta*);
    };
}
