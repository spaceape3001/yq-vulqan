////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "UISeparatorWriter.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UISeparator)

namespace yq::tachyon {
    UISeparator::UISeparator(UIFlags flags) : UIElement(flags)
    {
    }
    
    UISeparator::UISeparator(const UISeparator& cp) : UIElement(cp)
    {
    }
    
    UISeparator::~UISeparator()
    {
    }
    
    UISeparator* UISeparator::clone() const 
    {
        return new UISeparator(*this);
    }
    void UISeparator::render()
    {
        ImGui::Separator();
    }

    void UISeparator::init_meta()
    {
        auto w = writer<UISeparator>();
        w.description("Horizontal Separator");
    }
}
