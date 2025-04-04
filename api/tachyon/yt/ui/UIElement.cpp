////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElement.hpp"
#include <cassert>
#include <yt/ui/MyImGui.hpp>

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
        bool measure    = m_flags.any({F::AlwaysMeasure, F::MeasureNext});
        m_flags -= F::MeasureNext;
        
        if(measure)
            m_start = ImGui::GetCursorScreenPos();
        // eventually want to capture sizes (optional)
        render();
        if(measure)
            m_end = ImGui::GetCursorScreenPos();
    }
}
