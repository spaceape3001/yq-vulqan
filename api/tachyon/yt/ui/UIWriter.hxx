////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIWriter.hpp>
#include <yt/ui/Widget.hpp>
#include <ya/uis/UIButton_Post.hpp>
#include <ya/uis/UIButton_WidgetCallback.hpp>
#include <ya/uis/UIMenuItem_Post.hpp>
#include <ya/uis/UIMenuItem_WidgetCallback.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {
    template <SomePost P>
    UIWriter    UIWriter::button(std::string_view text, post_k<P>)
    {
        if(!addable())
            return {};
        return *this << new UIButton_Post<P>(text);
    }
    
    template <SomePost P>
    UIWriter    UIWriter::button(std::string_view text, const Vector2F& size, post_k<P>)
    {
        if(!addable())
            return {};
        return *this << new UIButton_Post<P>(text, size);
    }

    template <SomeWidget W>
    UIWriter    UIWriter::button(std::string_view text, void (W::*fn)())
    {
        if(!addable())
            return {};
        return *this << new UIButton_WidgetCallback<W>(text, fn);
    }
    

    template <SomeWidget W>
    UIWriter    UIWriter::button(std::string_view text, const Vector2F& size, void (W::*fn)())
    {
        if(!addable())
            return {};
        return *this << new UIButton_WidgetCallback<W>(text, size, fn);
    }
    
    
    ////////////////////////////////////////////////////////////////////////////

    template <SomeWidget W>
    UIWriter    UIWriter::menuitem(std::string_view name, void (W::*fn)())
    {
        if(!addable())
            return {};
        return *this << new UIMenuItem_WidgetCallback<W>(name, fn);
    }
    
    
    template <SomeWidget W>
    UIWriter    UIWriter::menuitem(std::string_view name, std::string_view scut, void (W::*fn)())
    {
        if(!addable())
            return {};
        return *this << new UIMenuItem_WidgetCallback<W>(name, scut, fn);
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
