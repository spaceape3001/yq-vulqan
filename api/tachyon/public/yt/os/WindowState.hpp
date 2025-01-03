////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/shape/Rectangle2.hpp>
#include <yq/shape/Size2.hpp>
#include <yt/api/ID.hpp>
#include <yt/typedef/monitor.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    enum class WindowFlag : uint8_t {
        AutoIconify,        //!< Auto Iconified (full screen on focus loss)
        Closed,             //!< Have we been closed?
        Decorated,          //!< Window decorations (ie, border, etc?)
        FixedAspect,        //!< Fixed aspect ratio
        Floating,           //!< Floating
        Focused,            //!< Focused
        FocusOnShow,        //!< Auto-focused when shown
        Hovered,            //!< Cursor over content area?
        Iconified,          //!< Iconified
        Maximized,          //!< Maximized
        MousePassThrough,   //!< Mouse being passed through (needs to be undecorated)
        RawMouseMotion,     //!< Raw Mouse Motion
        Resizable,          //!< Resizable
        Transparent,        //!< Transparent frame buffer?
        Visible             //!< Visible
    };
    
    using WindowFlags = Flags<WindowFlag, uint32_t>;
    
    struct WindowState {
        std::string             title;          //!< Window title
        WindowFlags             flags{};        //!< Window flags
        Vector2I                position{};     //!< Window position
        MonitorID               monitor{};      //!< Monitor (might need to alter to non-glfw...)
        Size2I                  aspect{-1,-1};  //!< Fixed aspect ratio (-1 is the don't care value)
        Size2I                  max{-1,-1};     //!< Max size (-1 is the don't care value)
        Size2I                  min{-1,-1};     //!< Min size (-1 is the don't care value)
        Size2I                  area{};         //!< Content area (in screen adjusted units)
        Size2I                  pixels{};       //!< Frame buffer size in pixels
        Vector2F                scale{1.f,1.f};
        float                   opacity = 1.f;  //!< Opacity 
    };
}