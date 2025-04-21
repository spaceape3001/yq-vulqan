////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIGenerator.hpp"
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIGenerator)

namespace yq::tachyon {
    UIGenerator::UIGenerator(UIFlags flags) : UIElement(flags)
    {
    }
    
    UIGenerator::~UIGenerator()
    {
    }
    
    void UIGenerator::init_info()
    {
        auto w = writer<UIGenerator>();
        w.description("UI Element Generator");
    }
}
