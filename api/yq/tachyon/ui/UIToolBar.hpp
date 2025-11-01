////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindow.hpp>
#include <yq/tachyon/typedef/uimisc.hpp>
#include <yq/tachyon/enum/Cardinal.hpp>

namespace yq::tachyon {
    class UIToolBarWriter;
    
    class UIToolBar : public UIWindow {
        YQ_OBJECT_DECLARE(UIToolBar, UIWindow)
    public:
        using Writer = UIToolBarWriter;

        UIToolBar(Cardinal, std::string_view, UIFlags flags={});
        UIToolBar(Vector2F, std::string_view, UIFlags flags={});
        UIToolBar(const UIToolBar&);
        ~UIToolBar();

        float       thickness() const;
        void        pivot(set_k, Vector2F);
        
        static void init_meta();

    protected:
        UIToolBar*  clone() const;
        void        render() override;
        
    private:
        unsigned    m_number       = 0;    // An inward creep of rows/columns
        
        Vector2F    pivot_get() const;
        void        pivot_set(const Vector2F&);
    };
}
