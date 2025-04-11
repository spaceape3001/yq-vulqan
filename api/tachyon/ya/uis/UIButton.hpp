////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElement.hpp>
#include <string_view>
#include <string>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class UIButtonWriter;
    
    class UIButton : public UIElement {
        YQ_OBJECT_DECLARE(UIButton, UIElement)
    public:
        using Writer = UIButtonWriter;

        UIButton(std::string_view, const Size2F& size=ZERO);
        UIButton(const UIButton&);
        virtual ~UIButton();
        void            render();
        virtual void    triggered();
        const char*     title() const;
        
        static void init_info();
    protected:
        UIButton*       clone() const;
    private:
        std::string     m_text;
        Size2F          m_size;
    };
}
