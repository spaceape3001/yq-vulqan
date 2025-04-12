////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElementWriter.hpp>
#include <yt/enum/UICardinal.hpp>
#include <yt/typedef/post.hpp>
#include <yt/typedef/widget.hpp>
#include <yq/typedef/size2.hpp>
#include <yq/typedef/vector2.hpp>
#include <yt/keywords.hpp>
#include <string_view>

namespace yq::tachyon {
    class UIElements;
    class Widget;
    class WidgetInfo;
    class UIAssetImageWriter;
    class UIButtonWriter;
    class UICenterAlignWriter;
    class UIHBoxWriter;
    class UIImageWriter;
    class UITextLabelWriter;
    class UIMenuWriter;
    class UIMenuBarWriter;
    class UIRightAlignWriter;
    class UISpacerWriter;
    class UIToolBarWriter;
    
    class UIElementsWriter : public UIElementWriter {
    public:
        
        UIElementsWriter();
        UIElementsWriter(Widget*);
        UIElementsWriter(WidgetInfo*);
        UIElementsWriter(UIElements*);
        UIElementsWriter(const UIElementsWriter&);
        ~UIElementsWriter();
        
        UIElements*             element();
        
        /*! Appends a new UI element (no checking if it's the right spot to go, no new writer)
            \note This routine assumes ownership, may delete the item 
            prior to return.
        */
        UIElementsWriter&       operator<<(UIElement*);
        
        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        UIButtonWriter          button(std::string_view);
        UIButtonWriter          button(std::string_view, const Size2F& size);

        template <SomePost P>
        UIButtonWriter          button(std::string_view, post_k<P>);

        template <SomePost P>
        UIButtonWriter          button(std::string_view, const Size2F& size, post_k<P>);

        template <SomeWidget W>
        UIButtonWriter          button(std::string_view, void (W::*)());

        template <SomeWidget W>
        UIButtonWriter          button(std::string_view, const Size2F& size, void (W::*)());

        //! The contents will be centered (as best as it can do)
        UICenterAlignWriter     center(align_k);
        
        //! The contents within will all be placed same line
        UIHBoxWriter            hbox();
        
        //! Will display the specified image/texture (using the asset-system)
        UIAssetImageWriter      image(std::string_view);
        
        //! Will display the specified image/texture (using the asset-system) using this FIXED size
        UIAssetImageWriter      image(std::string_view, const Size2F&);
        
        UITextLabelWriter       label(std::string_view);

        UIMenuWriter            menu(std::string_view);


        /*! \brief  Right align the contents
        
            This will right align the contents of it's object (so, it's technically
            an items collection that gets created.
        */
        UIRightAlignWriter      right(align_k);
        
        UISpacerWriter          spacer(const Size2F&);
        
    protected:
    
        /*! \brief Adds item to the elements
        
            \note This routine assumes ownership, may delete the item 
            prior to return (which is why it'll return false).
        */
        bool    add(UIElement*);
        
        template <typename U, typename ... Args>
        typename U::Writer make(Args... args)
        {
            U*  ret = new U(std::forward<Args>(args)...);
            if(add(ret)){
                return typename U::Writer(ret);
            } else {
                return typename U::Writer();
            }
        }
        
    private:
        static UIElements*      attach(Widget*);
        static UIElements*      attach(WidgetInfo*);
    };
}
