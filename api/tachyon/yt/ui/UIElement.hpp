////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>
#include <yq/core/Flags.hpp>

namespace yq::tachyon {
    struct ViContext;
    class Widget;

    class UIElement {
    public:
        UIElement();
        UIElement(const UIElement&);
        virtual ~UIElement();
        
        virtual UIElement*     clone() const = 0;
        
        //! Shouldn't generally be overriden aside from one/two instances
        virtual void    draw();
        
    protected:

        virtual void    render() = 0;

        //! Called if there's an if-show/perform test inside render
        virtual void    content() {}
        
        //! Valid during clone & render
        static Widget&  widget();
        
        enum class F : uint8_t {
            // LIMITED event select here ???
        };
        
        Flags<F>        m_flags;
        
    private:
        friend class Widget;
        static thread_local Widget*     s_widget;
        static thread_local ViContext*  s_context;
    };
    
    template <typename T>
    concept SomeUIElement  = std::derived_from<T,UIElement>;
}
