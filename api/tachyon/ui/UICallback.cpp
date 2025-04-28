////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UICallback.hpp"
#include <tachyon/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UICallback)

namespace yq::tachyon {
    UICallback::UICallback(UIFlags flags) : UIElement(flags)
    {
    }
    
    UICallback::UICallback(const UICallback& cp) : UIElement(cp)
    {
    }
    
    UICallback::~UICallback()
    {
    }
    
    void UICallback::init_info()
    {
        auto w = writer<UICallback>();
        w.description("Callback UI Element");
    }
}
