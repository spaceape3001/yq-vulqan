////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIItems.hpp>
#include <yt/keywords.hpp>

namespace yq::tachyon {
    class UIMenu : public UIItems {
    public:
        UIMenu(std::string_view);
        UIMenu(const UIMenu&);
        virtual ~UIMenu();
        
        virtual UIMenu*     clone() const override;

    protected:
        virtual void        render() override;

    private:
        std::string     m_name;
    };
}
