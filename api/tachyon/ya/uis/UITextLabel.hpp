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
        YQ_OBJECT_DECLARE(UITextLabel, UIElement)
    public:
        UITextLabel(std::string_view kString, UIFlags flags={});
        UITextLabel(const UITextLabel&);
        virtual ~UITextLabel();
        void    render() override;
        
        static void init_info();
        
    protected:
        UITextLabel*  clone() const override;
    private:
        std::string     m_text;
    };
}
