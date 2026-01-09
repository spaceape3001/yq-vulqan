////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UILineInput.hpp>

namespace yq::tachyon {
    template <SomeWidget W>
    class UILineInput_WidgetCallback : public UILineInput {
    public:
        typedef void(W::*FN)();
    
        UILineInput_WidgetCallback(FN fn, std::string_view label={}, UIFlags flags={}) : UILineInput(label, flags), m_function(fn)
        {
        }
    
        UILineInput_WidgetCallback(const UILineInput_WidgetCallback&cp) : UILineInput(cp), m_function(cp.m_function)
        {
        }
        
        void triggered() override
        {
            Widget*w    = widget();
            if(w && m_function)
                (w->*m_function)();
        }
        
        UILineInput_WidgetCallback* clone() const override
        {
            return new UILineInput_WidgetCallback(*this);
        }
        
    private:
        FN      m_function;
    
    };

    template <SomeWidget W>
    class UILineInput_WidgetCallbackWithString : public UILineInput {
    public:
        typedef void(W::*FN)(const std::string&);
    
        UILineInput_WidgetCallbackWithString(FN fn, std::string_view label={}, UIFlags flags={}) : UILineInput(label, flags), m_function(fn)
        {
        }
    
        UILineInput_WidgetCallbackWithString(const UILineInput_WidgetCallbackWithString&cp) : UILineInput(cp), m_function(cp.m_function)
        {
        }
        
        void triggered() override
        {
            Widget*w    = widget();
            if(w && m_function){
                std::string data(text());
                (w->*m_function)(data);
            }
        }
        
        UILineInput_WidgetCallbackWithString* clone() const override
        {
            return new UILineInput_WidgetCallbackWithString(*this);
        }
        
    private:
        FN      m_function;
    };

    template <SomeWidget W>
    class UILineInput_WidgetCallbackWithStringView : public UILineInput {
    public:
        typedef void(W::*FN)(std::string_view);
    
        UILineInput_WidgetCallbackWithStringView(FN fn, std::string_view label={}, UIFlags flags={}) : UILineInput(label, flags), m_function(fn)
        {
        }
    
        UILineInput_WidgetCallbackWithStringView(const UILineInput_WidgetCallbackWithStringView&cp) : UILineInput(cp), m_function(cp.m_function)
        {
        }
        
        void triggered() override
        {
            Widget*w    = widget();
            if(w && m_function)
                (w->*m_function)(text());
        }
        
        UILineInput_WidgetCallbackWithStringView* clone() const override
        {
            return new UILineInput_WidgetCallbackWithStringView(*this);
        }
        
    private:
        FN      m_function;
    };
}
