////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIWindow.hpp>
#include <yt/typedef/uimisc.hpp>
#include <yt/enum/UICardinal.hpp>

namespace yq::tachyon {
    class UIToolBar : public UIWindow {
    public:
        UIToolBar(UICardinal, std::string_view, UIFlags flags={});
        UIToolBar(Vector2F, std::string_view, UIFlags flags={});
        UIToolBar(const UIToolBar&);
        ~UIToolBar();

        float       thickness() const;
        void        pivot(set_k, Vector2F);

    protected:
        UIToolBar*  clone() const;
        void        render() override;
        
    private:
        unsigned    m_number       = 0;    // An inward creep of rows/columns
    };
}
