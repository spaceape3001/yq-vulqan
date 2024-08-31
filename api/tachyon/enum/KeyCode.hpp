////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! \brief Keycodes.... 

        These are the keycodes native to our codebase....
        
        Mapping to GLFW codes, ie, the stuff the keyboard can generate w/o 
        modifier interpretation.
    */
    YQ_ENUM(KeyCode, ,
        None            = 0,
        Unknown,
        Space,
        Apostrophe,
        Comma,
        Minus,
        Period,
        Slash,
        Zero, One, Two,   Three, Four,
        Five, Six, Seven, Eight, Nine,
        Semicolon,
        Equal,
        A, B, C, D, E, F, G, H, I, J, K, L, M,
        N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
        LeftBracket,
        Backslash,
        RightBracket,
        GraveAccent,
        
            //  non-US 1
        World1,
        
            //  non-us 2
        World2,
        Escape,
        Enter,
        Tab,
        Backspace,
        Insert,
        Delete,
        RightArrow,
        LeftArrow,
        DownArrow,
        UpArrow,
        PageUp,
        PageDown,
        Home,
        End,
        CapsLock,
        ScrollLock,
        NumLock,
        PrintScreen,
        Pause,
        F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10,
        F11, F12, F13, F14, F15, F16, F17, F18, F19, F20,
        F21, F22, F23, F24, F25,
        Kp0, Kp1, Kp2, Kp3, Kp4, Kp5, Kp6, Kp7, Kp8, Kp9,
        KpDecimal,
        KpDivide,
        KpMultiply,
        KpSubtract,
        KpAdd,
        KpEnter,
        KpEqual,
        LeftShift,
        LeftControl,
        LeftAlt,
        LeftSuper,
        RightShift,
        RightControl,
        RightAlt,
        RightSuper,
        Menu,
        
            //  Modifiers when it's ambgious (these can be mucked with)
        
        ModShift,
        ModControl,
        ModAlt,
        ModSuper,
        
            // Gamepad support
        
        GpStart,
        GpBack,
        GpFaceLeft,
        GpFaceRight,
        GpFaceUp,
        GpFaceDown,
        GpDPadLeft,
        GpDPadRight,
        GpDPadUp,
        GpDPadDown,
        GpL1,   // bumper
        GpR1,   // bumper
        GpL2,   // trigger
        GpR2,   // trigger
        GpL3,   // stick
        GpR3,   // stick
        GpLStickLeft,
        GpLStickRight,
        GpLStickUp,
        GpLStickDown,
        GpRStickLeft,
        GpRStickRight,
        GpRStickUp,
        GpRStickDown,
        
            //  Mouse support
        
        MsBtnLeft,
        MsBtnMiddle,
        MsBtnRight,
        MsX1, 
        MsX2, 
        MsWheelX, 
        MsWheelY
    )
    
    enum class KeyCodex : uint8_t {
        GLFW,
        ImGui
    };
    
    int         encode(KeyCode, KeyCodex);
    int         encode_glfw(KeyCode);
    
    /*! \brief Encodes ImGui keycode
    
        \note return type is integer to avoid an inclusion of imgui.h
    */
    int         encode_imgui(KeyCode);
    
    KeyCode     keycode(int, KeyCodex);
    KeyCode     keycode_glfw(int);
    KeyCode     keycode_imgui(int);
    
    //  Direct conversion, GLFW to IMGUI
    int         glfw_to_imgui(int);
    
    // TRUE if the key is an axis with a variable input
    bool        is_analog(KeyCode);
}

YQ_TYPE_DECLARE(yq::tachyon::KeyCode)
