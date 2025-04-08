////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIMenuItem.hpp>
#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    template <SomeWidget W>
    class UIMenuItem_WidgetCallback : public UIMenuItem {
    public:
    
        typedef void (W::*FN)();
    
        UIMenuItem_WidgetCallback(std::string_view kName, UIFlags flags, FN fn) : 
            UIMenuItem(kName, "", flags), m_function(fn)
        {
            assert(m_function);
        }
        
        UIMenuItem_WidgetCallback(std::string_view kName, std::string_view sCut, UIFlags flags, FN fn) : 
            UIMenuItem(kName, sCut, flags), m_function(fn)
        {
            assert(m_function);
        }
        
        UIMenuItem_WidgetCallback(const UIMenuItem_WidgetCallback&cp) : UIMenuItem(cp), m_function(cp.m_function)
        {
        }
        
        ~UIMenuItem_WidgetCallback()
        {
        }

        virtual UIMenuItem_WidgetCallback*     clone() const 
        {
            return new UIMenuItem_WidgetCallback(*this);
        }
    
    protected:
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
