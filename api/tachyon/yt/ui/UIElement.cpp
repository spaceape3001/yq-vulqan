////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElement.hpp"
#include <cassert>

namespace yq::tachyon {
    thread_local Widget*     UIElement::s_widget       = nullptr;
    thread_local ViContext*  UIElement::s_context    = nullptr;

    Widget&  UIElement::widget()
    {
        assert(s_widget);
        return *s_widget;
    }

    UIElement::UIElement()
    {
    }
    
    UIElement::UIElement(const UIElement&)
    {
    }
    
    UIElement::~UIElement()
    {
    }
    
    void    UIElement::draw()
    {
        // eventually want to capture sizes (optional)
        render();
    }
}
