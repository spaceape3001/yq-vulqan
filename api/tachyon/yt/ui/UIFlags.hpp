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
        FrameStyle,
        HorizontalScrollBar,
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
        SetPosition,
        SetPositionOnce,
        UnsavedDocument
    };
    
    using UIFlags = Flags<UIFlag,uint128_t>;
}
