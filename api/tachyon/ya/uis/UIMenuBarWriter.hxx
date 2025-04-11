////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "UIMenuBarWriter.hpp"
#include <ya/uis/UIMenuItem_Post.hpp>
#include <ya/uis/UIMenuItem_WidgetCallback.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {
    template <SomePost P>
    UIMenuItemWriter    UIMenuBarWriter::menuitem(std::string_view text, post_k<P>)
    {
        return make<UIMenuItem_Post<P>>(text);
    }

    template <SomePost P>
    UIMenuItemWriter    UIMenuBarWriter::menuitem(std::string_view text, std::string_view scut, post_k<P>)
    {
        return make<UIMenuItem_Post<P>>(text,scut);
    }

    template <SomeWidget W>
    UIMenuItemWriter    UIMenuBarWriter::menuitem(std::string_view text, void (W::*fn)())
    {
        return make<UIMenuItem_WidgetCallback<W>>(text, fn);
    }
    
    template <SomeWidget W>
    UIMenuItemWriter    UIMenuBarWriter::menuitem(std::string_view text, std::string_view scut, void (W::*fn)())
    {
        return make<UIMenuItem_WidgetCallback<W>>(text, scut, fn);
    }
}
