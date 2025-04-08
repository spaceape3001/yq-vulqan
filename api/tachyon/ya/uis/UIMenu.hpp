////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>
#include <yt/keywords.hpp>

namespace yq::tachyon {
    class UIMenu : public UIElements {
    public:
        UIMenu(std::string_view, UIFlags flags={});
        UIMenu(const UIMenu&);
        virtual ~UIMenu();
        
        virtual UIMenu*     clone() const override;

        virtual const char*   title() const override;

    protected:
        virtual void        render() override;

    private:
        std::string     m_name;
    };
}
