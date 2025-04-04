////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIItems.hpp>
#include <yt/keywords.hpp>

namespace yq::tachyon {
    class MenuBar : public UIItems {
    public:
        MenuBar();
        MenuBar(main_k);
        MenuBar(const MenuBar&);
        virtual ~MenuBar();
        
        virtual MenuBar*     clone() const override;

    protected:
        virtual void        render() override;

    private:
        bool    m_isMain;
    };
}
