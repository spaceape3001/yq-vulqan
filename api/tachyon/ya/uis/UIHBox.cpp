////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIHBox.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

namespace yq::tachyon {
    UIHBox::UIHBox(UIFlags flags) : UIElements(flags|UIFlag::Horizontal)
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
}

