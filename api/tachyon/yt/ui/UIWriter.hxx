////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIWriter.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/uis/UIMenuItem_Post.hpp>
#include <yt/uis/UIMenuItem_WidgetCallback.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {
    template <SomeWidget W>
    UIWriter    UIWriter::menuitem(std::string_view name, void (W::*fn)())
    {
        if(!addable())
            return {};
        return *this << new UIMenuItem_WidgetCallback(name, fn);
    }
    
    
    template <SomeWidget W>
    UIWriter    UIWriter::menuitem(std::string_view name, std::string_view scut, void (W::*fn)())
    {
        if(!addable())
            return {};
        return *this << new UIMenuItem_WidgetCallback(name, scut, fn);
    }

    template <SomePost P>
    UIWriter    UIWriter::menuitem(std::string_view name, post_k<P>)
    {
        if(!addable())
            return {};
        return *this << new UIMenuItem_Post<P>(name);
    }
    
    template <SomePost P>
    UIWriter    UIWriter::menuitem(std::string_view name, std::string_view scut, post_k<P>)
    {
        if(!addable())
            return {};
        return *this << new UIMenuItem_Post<P>(name, scut);
    }
}
