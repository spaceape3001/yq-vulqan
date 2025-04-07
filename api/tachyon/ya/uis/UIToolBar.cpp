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

    bool    UIToolBar::do_horizontal() const
    {
        return undefined(m_orientation) || horizontal(m_orientation);
    }

    void    UIToolBar::orientation(set_k, horzvert_t hv)
    {
        m_orientation   = hv;
        if(do_horizontal()){
        } else {
        }
    }

    void    UIToolBar::render(items_k)
    {
        if(do_horizontal()){
            for(UIElement* ui : m_items){
                ImGui::SameLine();
                ui->draw();
            }
        } else {
            for(UIElement* ui : m_items)
                ui->draw();
        }
    
    }
}
