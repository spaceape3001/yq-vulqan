////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIItems.hpp>
#include <yt/keywords.hpp>

namespace yq::tachyon {
    class Menu : public UIItems {
    public:
        Menu(std::string_view);
        Menu(const Menu&);
        virtual ~Menu();
        
        virtual Menu*     clone() const override;

    protected:
        virtual void        render() override;

    private:
        std::string     m_name;
    };
}
