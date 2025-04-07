////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIToolBar.hpp"
#include <yt/ui/UIUtils.hpp>

namespace yq::tachyon {
    UIToolBar::UIToolBar(horzvert_t hv, std::string_view title) : UIWindow(title, { UIFlag::NoTitleBar })
    {
        orientation(SET, hv);
    }
    
    UIToolBar::UIToolBar(const UIToolBar& cp) : UIWindow(cp), m_orientation(cp.m_orientation)
    {
    }
    
    UIToolBar::~UIToolBar()
    {
    }
    
    UIToolBar*  UIToolBar::clone() const
    {
        return new UIToolBar(*this);
    }

    void    UIToolBar::orientation(set_k, horzvert_t hv)
    {
        if(undefined(hv) || horizontal(hv)){
        } else if(vertical(hv)){
        }
    }
}
