////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIToolBar.hpp"
#include <yt/ui/UIUtils.hpp>
#include <yq/shape/Size2.hxx>
#include <yq/vector/Vector2.hxx>

namespace yq::tachyon {
    static constexpr const UIFlags  kToolBarFlags   = { UIFlag::NoTitleBar, UIFlag::SetSize };
    static constexpr float     kMinSize    = 20;

    UIFlags  UIToolBar::flags_for(UIBorder b)
    {
        switch(b){
        case UIBorder::NNW:
            return UIFlags({ UIFlag::Horizontal });
        case UIBorder::North:
            return UIFlags({ UIFlag::Horizontal });
        case UIBorder::NNE:
            return UIFlags({ UIFlag::Horizontal, UIFlag::Reverse });
        case UIBorder::ENE:
            return {};
        case UIBorder::East:
            return {};
        case UIBorder::ESE:
            return UIFlags({ UIFlag::Reverse });
        case UIBorder::SSE:
            return UIFlags({ UIFlag::Horizontal, UIFlag::Reverse });
        case UIBorder::South:
            return UIFlags({ UIFlag::Horizontal });
        case UIBorder::SSW:
            return UIFlags({ UIFlag::Horizontal });
        case UIBorder::WSW:
            return UIFlags({ UIFlag::Reverse });
        case UIBorder::West:
            return {};
        case UIBorder::WNW:
            return {};
        default:
            return {};
        }
    }

    UIToolBar::UIToolBar(UIBorder b, std::string_view title, UIFlags flags) : 
        UIWindow(title, flags | kToolBarFlags | flags_for(b)), m_border(b)
    {
        m_size  = { kMinSize, kMinSize };
    }
    

    UIToolBar::UIToolBar(const UIToolBar& cp) : UIWindow(cp), m_border(cp.m_border), m_orientation(cp.m_orientation)
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

    void    UIToolBar::render() 
    {
        Size2F avail(ImGui::GetContentRegionAvail());
        m_size          = avail.emax(kMinSize);
    }

    void    UIToolBar::orientation(set_k, horzvert_t hv)
    {
        m_orientation   = hv;
        if(do_horizontal()){
            flag(SET, UIFlag::Horizontal);
        } else {
            flag(CLEAR, UIFlag::Horizontal);
        }
    }
}
