////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElement.hpp>
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
    };
}
