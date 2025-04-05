////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIItems.hpp>
#include <yt/keywords.hpp>

namespace yq::tachyon {
    class UIMenuBar : public UIItems {
    public:
        UIMenuBar();
        UIMenuBar(main_k);
        UIMenuBar(const UIMenuBar&);
        virtual ~UIMenuBar();
        
        virtual UIMenuBar*     clone() const override;

    protected:
        virtual void        render() override;

    private:
        bool    m_isMain;
    };
}
