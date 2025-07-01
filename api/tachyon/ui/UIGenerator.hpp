////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>
#include <functional>
#include <cassert>
#include <utility>

namespace yq::tachyon {
    class UIGenerator : public UIElement {
        YQ_OBJECT_DECLARE(UIGenerator, UIElement)
    public:
        UIGenerator(UIFlags flags={});
        ~UIGenerator();
        static void init_info();
        
        UIElement* copy() const override final;
        
        virtual Tristate is(const UIElementMeta& baseInfo) const override;

        virtual const UIElementMeta*    ui_info() const { return nullptr; }
    };
}
