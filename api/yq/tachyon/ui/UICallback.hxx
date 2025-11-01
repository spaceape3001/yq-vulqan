////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/ui/UICallback.hpp>

namespace yq::tachyon {
    template <SomeWidget W>
    class UICallback_Widget : public UICallback {
    public:
        typedef void (W::*FN)();
        
        UICallback_Widget(FN fn, UIFlags flags={}) : UICallback(flags), m_function(fn)
        {
            assert(m_function);
        }
        
        UICallback_Widget(const UICallback_Widget& cp) : UICallback(cp), m_function(cp.m_function)
        {
        }
        
        ~UICallback_Widget()
        {
        }
        
        UICallback_Widget* clone() const override
        {
            return new UICallback_Widget(*this);
        }
        
    protected:
        void    render() override
        {
            W*  w = dynamic_cast<W*>(widget());
            if(!w)
                return ;
            if(!m_function)
                return;
            (w->*m_function)();
        }
    
        FN  m_function;
    };
}
