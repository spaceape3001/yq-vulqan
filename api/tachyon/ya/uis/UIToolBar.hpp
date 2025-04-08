////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIWindow.hpp>
#include <yt/typedef/uimisc.hpp>
#include <yt/enum/UIBorder.hpp>

namespace yq::tachyon {
    class UIToolBar : public UIWindow {
    public:
        UIToolBar(UIBorder, std::string_view, UIFlags flags={});
        UIToolBar(const UIToolBar&);
        ~UIToolBar();
        
        void    orientation(set_k, horzvert_t);

    protected:
        UIToolBar*  clone() const;
        
        void        render() override;
        
    private:
        
        static UIFlags  flags_for(UIBorder);
        
        UIBorder    m_border;
    
        bool    do_horizontal() const;
    
        horzvert_t  m_orientation;
    };
}
