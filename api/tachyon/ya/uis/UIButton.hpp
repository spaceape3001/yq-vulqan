////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElement.hpp>
#include <string_view>
#include <string>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    class UIButton : public UIElement {
    public:
        UIButton(std::string_view, const Vector2F& size=ZERO);
        UIButton(const UIButton&);
        virtual ~UIButton();
        void            render();
        virtual void    triggered();
        const char*     title() const;
    protected:
        UIButton*       clone() const;
    private:
        std::string     m_text;
        Vector2F        m_size;
    };
}
