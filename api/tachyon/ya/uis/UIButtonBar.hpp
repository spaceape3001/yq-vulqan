////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIWindow.hpp>
#include <tachyon/typedef/uimisc.hpp>
#include <tachyon/enum/Cardinal.hpp>

namespace yq::tachyon {
    class UIButtonBarWriter;
    
    class UIButtonBar : public UIWindow {
        YQ_OBJECT_DECLARE(UIButtonBar, UIWindow)
    public:
        using Writer = UIButtonBarWriter;

        UIButtonBar(Cardinal, std::string_view, UIFlags flags={});
        UIButtonBar(Vector2F, std::string_view, UIFlags flags={});
        UIButtonBar(const UIButtonBar&);
        ~UIButtonBar();

        float       thickness() const;
        void        pivot(set_k, Vector2F);
        
        static void init_info();

    protected:
        UIButtonBar*  clone() const;
        void        render() override;
        
    private:
        unsigned    m_number       = 0;    // An inward creep of rows/columns
        
        Vector2F    pivot_get() const;
        void        pivot_set(const Vector2F&);
    };
}
