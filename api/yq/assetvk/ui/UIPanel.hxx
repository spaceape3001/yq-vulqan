////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/ui/UIPanel.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/trait/numbers.hpp>
#include <yq/tachyon/ui/UIStyle.hpp>

namespace yq::tachyon {
    struct UIPanel::Context {
        AxBox2F available;
        AxBox2F current;
    };

    struct UIPanel::Calc {
        virtual ~Calc(){}
        virtual float   compute(const Context&) const = 0;
    };
    
    struct UIPanel::Fixed : public UIPanel::Calc {
        float       m_value;
        Fixed(float v) : m_value(v) {}
        
        float compute(const Context&) const override
        {
            return m_value;
        }
    };
        
    struct UIPanel::ScaledH : public Calc {
        float       m_scale;
        
        ScaledH(float s) : m_scale(s) {}
        float compute(const Context& u) const override
        {
            return m_scale * u.available.width();
        }
    };

    struct UIPanel::ScaledV : public Calc {
        float       m_scale;

        ScaledV(float s) : m_scale(s) {}

        float compute(const Context& u) const override
        {
            return m_scale * u.available.height();
        }
    };

    struct UIPanel::StyToolBar : public Calc {
        StyToolBar(){}
        float compute(const Context&) const override
        {
            return style().toolbar.thickness();
        }
    };

    struct UIPanel::UIDBottom : public Calc {
        std::string m_uid;
        UIDBottom(std::string_view uid) : m_uid(uid) {}
        float compute(const Context&) const override
        {
            UIWindow*   w   = window(m_uid);
            if(!w || w->invisible())
                return NaNf;
            return w->bottom();
        }
    };
    
    struct UIPanel::UIDLeft : public Calc {
        std::string m_uid;
        UIDLeft(std::string_view uid) : m_uid(uid) {}
        float compute(const Context&) const override
        {
            UIWindow*   w   = window(m_uid);
            if(!w || w->invisible())
                return NaNf;
            return w->left();
        }
    };
    
    struct UIPanel::UIDRight : public Calc {
        std::string m_uid;
        UIDRight(std::string_view uid) : m_uid(uid) {}
        float compute(const Context&) const override
        {
            UIWindow*   w   = window(m_uid);
            if(!w || w->invisible())
                return NaNf;
            return w->right();
        }
    };

    struct UIPanel::UIDTop : public Calc {
         std::string m_uid;
        UIDTop(std::string_view uid) : m_uid(uid) {}
        float compute(const Context&) const override
        {
            UIWindow*   w   = window(m_uid);
            if(!w || w->invisible())
                return NaNf;
            return w->top();
        }
   };

}


