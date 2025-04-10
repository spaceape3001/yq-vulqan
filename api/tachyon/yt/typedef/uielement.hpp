////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <concepts>

namespace yq::tachyon {
    class UIElement;
    class UIElementInfo;
    template <typename T>
    concept SomeUIElement  = std::derived_from<T,UIElement>;
}
