////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIFlags.hpp"
#include <yq/tachyon/MyImGui.hpp>

namespace ImGui {
    ImGuiChildFlags_  ChildFlag(UIFlag flag)
    {
        switch(flag){
        case UIFlag::Borders:
            return ImGuiChildFlags_Borders;
        case UIFlag::AlwaysUseWindowPadding:
            return ImGuiChildFlags_AlwaysUseWindowPadding;
        case UIFlag::ResizeX:
            return ImGuiChildFlags_ResizeX;
        case UIFlag::ResizeY:
            return ImGuiChildFlags_ResizeY;
        case UIFlag::AutoResizeX:
            return ImGuiChildFlags_AutoResizeX;
        case UIFlag::AutoResizeY:
            return ImGuiChildFlags_AutoResizeY;
        case UIFlag::AlwaysAutoResize:
            return ImGuiChildFlags_AlwaysAutoResize;
        case UIFlag::FrameStyle:
            return ImGuiChildFlags_FrameStyle;
        case UIFlag::NavFlattened:
            return ImGuiChildFlags_NavFlattened;
        default:
            return ImGuiChildFlags_None;
        }
    }
    
    ImGuiChildFlags  ChildFlags(UIFlags flags)
    {
        ImGuiChildFlags ret = ImGuiChildFlags_None;
        if(flags(UIFlag::Borders))
            ret |= ImGuiChildFlags_Borders;
        if(flags(UIFlag::AlwaysUseWindowPadding))
            ret |= ImGuiChildFlags_AlwaysUseWindowPadding;
        if(flags(UIFlag::ResizeX))
            ret |= ImGuiChildFlags_ResizeX;
        if(flags(UIFlag::ResizeY))
            ret |= ImGuiChildFlags_ResizeY;
        if(flags(UIFlag::AutoResizeX))
            ret |= ImGuiChildFlags_AutoResizeX;
        if(flags(UIFlag::AutoResizeY))
            ret |= ImGuiChildFlags_AutoResizeY;
        if(flags(UIFlag::AlwaysAutoResize))
            ret |= ImGuiChildFlags_AlwaysAutoResize;
        if(flags(UIFlag::FrameStyle))
            ret |= ImGuiChildFlags_FrameStyle;
        if(flags(UIFlag::NavFlattened))
            ret |= ImGuiChildFlags_NavFlattened;
        return ret;
    }

    ImGuiInputTextFlags_    TextFlag(UIFlag)
    {
        return {};   // TODO
    }
    
    ImGuiInputTextFlags     TextFlags(UIFlags)
    {
        return {};   // TODO
    }
    
    ImGuiWindowFlags_ WindowFlag(UIFlag flag)
    {
        switch(flag){
        case UIFlag::NoTitleBar:
            return ImGuiWindowFlags_NoTitleBar;
        case UIFlag::NoResize:
            return ImGuiWindowFlags_NoResize;
        case UIFlag::NoMove:
            return ImGuiWindowFlags_NoMove;
        case UIFlag::NoScrollBar:
            return ImGuiWindowFlags_NoScrollbar;
        case UIFlag::NoScrollWithMouse:
            return ImGuiWindowFlags_NoScrollWithMouse;
        case UIFlag::NoCollapse:
            return ImGuiWindowFlags_NoCollapse;
        case UIFlag::AlwaysAutoResize:
            return ImGuiWindowFlags_AlwaysAutoResize;
        case UIFlag::NoBackground:
            return ImGuiWindowFlags_NoBackground;
        case UIFlag::NoSavedSettings:
            return ImGuiWindowFlags_NoSavedSettings;
        case UIFlag::NoMouseInputs:
            return ImGuiWindowFlags_NoMouseInputs;
        case UIFlag::MenuBar:
            return ImGuiWindowFlags_MenuBar;
        case UIFlag::HorizontalScrollBar:
            return ImGuiWindowFlags_HorizontalScrollbar;
        case UIFlag::NoFocusOnAppearing:
            return ImGuiWindowFlags_NoFocusOnAppearing;
        case UIFlag::NoBringToFrontOnFocus:
            return ImGuiWindowFlags_NoBringToFrontOnFocus;
        case UIFlag::AlwaysVerticalScrollBar:
            return ImGuiWindowFlags_AlwaysVerticalScrollbar;
        case UIFlag::AlwaysHorizontalScrollBar:
            return ImGuiWindowFlags_AlwaysHorizontalScrollbar;
        case UIFlag::NoNavInputs:
            return ImGuiWindowFlags_NoNavInputs;
        case UIFlag::NoNavFocus:
            return ImGuiWindowFlags_NoNavFocus;
        case UIFlag::UnsavedDocument:
            return ImGuiWindowFlags_UnsavedDocument;
        case UIFlag::NoNav:
            return ImGuiWindowFlags_NoNav;
        case UIFlag::NoDecoration:
            return ImGuiWindowFlags_NoDecoration;
        case UIFlag::NoInputs:
            return ImGuiWindowFlags_NoInputs;
        default:
            return ImGuiWindowFlags_None;
        }
    }
    
    ImGuiWindowFlags WindowFlags(UIFlags flags)
    {
        ImGuiWindowFlags ret = ImGuiWindowFlags_None;
        if(flags(UIFlag::NoTitleBar))
            ret |= ImGuiWindowFlags_NoTitleBar;
        if(flags(UIFlag::NoResize))
            ret |= ImGuiWindowFlags_NoResize;
        if(flags(UIFlag::NoMove))
            ret |= ImGuiWindowFlags_NoMove;
        if(flags(UIFlag::NoScrollBar))
            ret |= ImGuiWindowFlags_NoScrollbar;
        if(flags(UIFlag::NoScrollWithMouse))
            ret |= ImGuiWindowFlags_NoScrollWithMouse;
        if(flags(UIFlag::NoCollapse))
            ret |= ImGuiWindowFlags_NoCollapse;
        if(flags(UIFlag::AlwaysAutoResize))
            ret |= ImGuiWindowFlags_AlwaysAutoResize;
        if(flags(UIFlag::NoBackground))
            ret |= ImGuiWindowFlags_NoBackground;
        if(flags(UIFlag::NoSavedSettings))
            ret |= ImGuiWindowFlags_NoSavedSettings;
        if(flags(UIFlag::NoMouseInputs))
            ret |= ImGuiWindowFlags_NoMouseInputs;
        if(flags(UIFlag::MenuBar))
            ret |= ImGuiWindowFlags_MenuBar;
        if(flags(UIFlag::HorizontalScrollBar))
            ret |= ImGuiWindowFlags_HorizontalScrollbar;
        if(flags(UIFlag::NoFocusOnAppearing))
            ret |= ImGuiWindowFlags_NoFocusOnAppearing;
        if(flags(UIFlag::NoBringToFrontOnFocus))
            ret |= ImGuiWindowFlags_NoBringToFrontOnFocus;
        if(flags(UIFlag::AlwaysVerticalScrollBar))
            ret |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
        if(flags(UIFlag::AlwaysHorizontalScrollBar))
            ret |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;
        if(flags(UIFlag::NoNavInputs))
            ret |= ImGuiWindowFlags_NoNavInputs;
        if(flags(UIFlag::NoNavFocus))
            ret |= ImGuiWindowFlags_NoNavFocus;
        if(flags(UIFlag::UnsavedDocument))
            ret |= ImGuiWindowFlags_UnsavedDocument;
        if(flags(UIFlag::NoNav))
            ret |= ImGuiWindowFlags_NoNav;
        if(flags(UIFlag::NoDecoration))
            ret |= ImGuiWindowFlags_NoDecoration;
        if(flags(UIFlag::NoInputs))
            ret |= ImGuiWindowFlags_NoInputs;
        return ret;
    }
}
