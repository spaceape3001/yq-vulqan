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
    class UIMenuItem : public UIElement {
        YQ_OBJECT_DECLARE(UIMenuItem, UIElement)
    public:
        UIMenuItem(std::string_view kName, std::string_view kShortcut="", UIFlags flags={});
        UIMenuItem(const UIMenuItem&);
        ~UIMenuItem();

        virtual const char*   title() const override;
        
        static void init_info();
        
    protected:
        virtual UIMenuItem*       clone() const override;
        virtual void  render() override;
        virtual void  triggered() { content(); }

    private:
        std::string     m_name;
        std::string     m_shortcut;
    };
}
