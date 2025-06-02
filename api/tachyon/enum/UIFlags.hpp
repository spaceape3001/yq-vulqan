////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/typedef/128.hpp>

namespace yq::tachyon {
    /*! \brief UI Flags
    
        These will be translated into the relevant ImGui flags
    */
    enum class UIFlag : uint8_t {
        AllowDuplicateId,
        AllowTabInput,
        AlwaysAutoResize,
        AlwaysHorizontalScrollBar,
        AlwaysOverwrite,
        AlwaysVerticalScrollBar,
        AlwaysUseWindowPadding,
        AutoClosePopups,
        AutoSelectAll,
        AutoCenterX,
        AutoCenterY,
        AutoResizeX,
        AutoResizeY,
        Borders,
        ButtonRepeat,
        CharsDecimal,
        CharsHexadecimal,
        CharsScientific,
        CharsUppercase,
        Closeable,
        CtrlEnterForNewLine,
        DisplayEmptyRefVal,
        EmitSignal,                 //!< Emit signal on changes/other (whether selection or what not)
        EnterReturnsTrue,
        EscapeClearsAll,
        ForceImageSize,             //!< Force the image size to specified (no resizing to accommodate)
        FrameStyle,
        Horizontal,
        HorizontalScrollBar,
        IgnoreSourceAspectRatio,    //!< Ignore the source image's aspect ratio
        Invisible,
        IsButton,                   //!< TRUE to set to a button
        IsChild,                    //!< TRUE to use begin/end child instead of raw begin/end
        IsTristate,                 //!< TRUE if we're tristate (instead of boolean)
        MenuBar,
        NavFlattened,
        NoBackground,
        NoBringToFrontOnFocus,
        NoCollapse,
        NoDecoration,
        NoFocusOnAppearing,
        NoHorizontalScroll,
        NoInputs,
        NoMouseInputs,
        NoMove,
        NoNav,
        NoNavDefaultFocus,
        NoNavFocus,
        NoNavInputs,
        NoResize,
        NoSavedSettings,
        NoScrollBar,
        NoScrollWithMouse,
        NoTabStop,
        NoTitleBar,
        NoUndoRedo,
        ParseEmptyRefVal,
        Password,
        ReadOnly,               //!< Set to disable editing (currently advisory)
        ResizeX,
        ResizeY,
        Reverse,
        SetPosition,
        SetPositionOnce,
        SetSize,
        SetSizeOnce,
        StretchToFull,          //!< Stretch to full size (toolbar is width)
        UnsavedDocument,
        Vertical,
        
        Transparent = NoBackground
    };
    
    using UIFlags = Flags<UIFlag,uint128_t>;
}
