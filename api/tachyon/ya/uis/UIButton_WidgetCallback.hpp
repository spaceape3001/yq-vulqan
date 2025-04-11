////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIButton.hpp>
#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    template <SomeWidget W>
    class UIButton_WidgetCallback : public UIButton {
    public:
    
        typedef void (W::*FN)();
    
        UIButton_WidgetCallback(std::string_view text, FN fn) : UIButton(text), m_function(fn)
        {
            assert(m_function);
        }
        
        UIButton_WidgetCallback(std::string_view text, const Size2F& size, FN fn) : UIButton(text, size), m_function(fn)
        {
            assert(m_function);
        }

        UIButton_WidgetCallback(const UIButton_WidgetCallback&cp) : UIButton(cp), m_function(cp.m_function)
        {
        }
        
        ~UIButton_WidgetCallback()
        {
        }

    protected:
        virtual UIButton_WidgetCallback*     clone() const 
        {
            return new UIButton_WidgetCallback(*this);
        }
    
        //  Letting the menu item handle render
        
        void    triggered() override
        {
            W*  w   = dynamic_cast<W*>(widget());
            if(w){
                (w->*m_function)();
            }
        }

    private:
        
        FN  m_function;
    };
}
