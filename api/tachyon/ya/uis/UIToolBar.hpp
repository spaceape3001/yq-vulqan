////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIWindow.hpp>
#include <yt/typedef/uimisc.hpp>

namespace yq::tachyon {
    class UIToolBar : public UIWindow {
    public:
        UIToolBar(horzvert_t, std::string_view);
        UIToolBar(const UIToolBar&);
        ~UIToolBar();
        
        UIToolBar*  clone() const;
        
        using UIWindow::render;
        
        
        void    render(items_k) override;
        
        void    orientation(set_k, horzvert_t);
        
    private:
        bool    do_horizontal() const;
    
        horzvert_t  m_orientation;
    };
}
