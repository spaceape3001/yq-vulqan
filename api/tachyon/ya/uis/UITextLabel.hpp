////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElement.hpp>
#include <string_view>
#include <string>

namespace yq::tachyon {
    class UITextLabel : public UIElement {
    public:
        UITextLabel(std::string_view kString);
        UITextLabel(const UITextLabel&);
        virtual ~UITextLabel();
        void    render() override;
        UITextLabel*  clone() const override;
    private:
        std::string     m_text;
    };
}
