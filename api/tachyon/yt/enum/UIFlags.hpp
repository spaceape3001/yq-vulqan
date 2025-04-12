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
        EnterReturnsTrue,
        EscapeClearsAll,
        ForceImageSize,             //!< Force the image size to specified (no resizing to accommodate)
        FrameStyle,
        Horizontal,
        HorizontalScrollBar,
        IgnoreSourceAspectRatio,    //!< Ignore the source image's aspect ratio
        Invisible,
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
        ReadOnly,
        ResizeX,
        ResizeY,
        Reverse,
        SetPosition,
        SetPositionOnce,
        SetSize,
        SetSizeOnce,
        StretchToFull,      //!< Stretch to full size (toolbar is width)
        UnsavedDocument,
        Vertical
    };
    
    using UIFlags = Flags<UIFlag,uint128_t>;
}
