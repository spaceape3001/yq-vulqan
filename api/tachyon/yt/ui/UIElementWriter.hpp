////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/enum/UIFlags.hpp>
#include <yt/keywords.hpp>
#include <yt/typedef/post.hpp>
#include <yt/typedef/tachyon.hpp>

namespace yq::tachyon {
    class Action;
    class UIElement;
    
    class UIElementWriter {
    public:
    
        UIElementWriter();
        UIElementWriter(UIElement*);
        UIElementWriter(const UIElementWriter&);
        ~UIElementWriter();

        UIElement*      element() { return m_ui; }
        operator UIElement*() { return m_ui; }

        //! Passes in pointer (note, the framework takes ownership)
        UIElementWriter action(Action*);
        
        template <SomePost P>
        UIElementWriter action(post_k<P>);
        template <SomeTachyon T>
        UIElementWriter action(void (T::*)());

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
