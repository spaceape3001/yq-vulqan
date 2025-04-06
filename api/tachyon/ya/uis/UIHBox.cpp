////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIHBox.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    UIHBox::UIHBox()
    {
    }
    
    UIHBox::UIHBox(const UIHBox& cp) : UIElements(cp)
    {
    }
    
    UIHBox::~UIHBox()
    {
    }
    
    UIHBox* UIHBox::clone() const
    {
        return new UIHBox(*this);
    }

    void    UIHBox::render(items_k) 
    {
        for(UIElement* ui : m_items){
            if(!ui) [[unlikely]]
                continue;
            ImGui::SameLine();
            ui->draw();
        }
    }
}

