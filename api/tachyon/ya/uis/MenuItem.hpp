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
    class MenuItem : public UIElement {
    public:
        MenuItem(std::string_view kName, std::string_view kShortcut="");
        MenuItem(const MenuItem&);
        ~MenuItem();

        virtual MenuItem*       clone() const override;
        
    protected:
        virtual void            render() override;

    private:
        std::string     m_name;
        std::string     m_shortcut;
    };
}
