////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "UIElementsWriter.hpp"
#include <ya/uis/UIButton_Post.hpp>
#include <ya/uis/UIButton_WidgetCallback.hpp>
#include <ya/uis/UIButtonWriter.hpp>

namespace yq::tachyon {
    template <SomePost P>
    UIButtonWriter    UIElementsWriter::button(std::string_view text, post_k<P>)
    {
        return make<UIButton_Post<P>>(text);
    }
    
    template <SomePost P>
    UIButtonWriter    UIElementsWriter::button(std::string_view text, const Size2F& size, post_k<P>)
    {
        return make<UIButton_Post<P>>(text, size);
    }

    template <SomeWidget W>
    UIButtonWriter    UIElementsWriter::button(std::string_view text, void (W::*fn)())
    {
        return make<UIButton_WidgetCallback<W>>(text, fn);
    }
    

    template <SomeWidget W>
    UIButtonWriter    UIElementsWriter::button(std::string_view text, const Size2F& size, void (W::*fn)())
    {
        return make<UIButton_WidgetCallback<W>>(text, size, fn);
    }
}
