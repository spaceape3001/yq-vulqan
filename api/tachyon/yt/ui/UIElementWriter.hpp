////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/enum/UIFlags.hpp>
#include <yt/keywords.hpp>
#include <tachyon/typedef/action.hpp>
#include <tachyon/typedef/post.hpp>
#include <tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {
    class UIElement;
    
    class UIElementWriter {
    public:
    
        UIElementWriter();
        UIElementWriter(UIElement*);
        UIElementWriter(const UIElementWriter&);
        ~UIElementWriter();

        UIElement*      element() { return m_ui; }
        operator UIElement*() { return m_ui; }

        //! Passes in pointer
        UIElementWriter action(ActionCPtr);
        
        template <SomePost P>
        UIElementWriter action(post_k<P>);
        template <SomeTachyon T>
        UIElementWriter action(void (T::*)());
        
        UIElementWriter action(visible_k, UIElement*);
        UIElementWriter action(visible_k, UIElementWriter&);
        //UIElementWriter action(visible_k, std::initializer_list<UIElement*>);
        //UIElementWriter action(visible_k, std::initializer_list<UIElementWriter&>);
        UIElementWriter action(visible_k, const std::string&);

        UIElementWriter flag(clear_k, UIFlag);
        UIElementWriter flag(set_k, UIFlag);

        UIElementWriter flags(clear_k, UIFlags);
        UIElementWriter flags(set_k, UIFlags);
        
        //! Sets the UID (user defined ID)
        UIElementWriter uid(std::string_view);

    protected:
        UIElement*      m_ui    = nullptr;
    };
}
