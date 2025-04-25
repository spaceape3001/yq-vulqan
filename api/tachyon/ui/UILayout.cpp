////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UILayout.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/logging.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UILayout)

namespace yq::tachyon {
    void UILayout::init_info()
    {
        auto w = writer<UILayout>();
        w.description("UI Layout");
    }
    
    UILayout::UILayout(UIFlags flags) : UIElements(flags)
    {
    }
    
    UILayout::UILayout(const UILayout& cp) : UIElements(cp)
    {
    }
    
    UILayout::~UILayout()
    {
    }
    
    UILayout*       UILayout::clone() const
    {
        return new UILayout(*this);
    }
}
