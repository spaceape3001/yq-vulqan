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
        YQ_OBJECT_DECLARE(UIToolBar, UIWindow)
    public:
        UIToolBar(UICardinal, std::string_view, UIFlags flags={});
        UIToolBar(Vector2F, std::string_view, UIFlags flags={});
        UIToolBar(const UIToolBar&);
        ~UIToolBar();

        float       thickness() const;
        void        pivot(set_k, Vector2F);
        
        static void init_info();

    protected:
        UIToolBar*  clone() const;
        void        render() override;
        
    private:
        unsigned    m_number       = 0;    // An inward creep of rows/columns
        
        Vector2F    pivot_get() const;
        void        pivot_set(const Vector2F&);
    };
}
