////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>

namespace yq::tachyon {
    struct ViContext;
    class Widget;

    class UIElement {
    public:
        UIElement();
        UIElement(const UIElement&);
        virtual ~UIElement();
        
        virtual UIElement*     clone() const = 0;
        
        void            draw();
        
    protected:

        virtual void    render() = 0;

        //! Called if there's an if-show/perform test inside render
        virtual void    content() {}
        
        //! Valid during clone & render
        static Widget&  widget();
        
    private:
        friend class Widget;
        static thread_local Widget*     s_widget;
        static thread_local ViContext*  s_context;
    };
    
    template <typename T>
    concept SomeUIElement  = std::derived_from<T,UIElement>;
}
