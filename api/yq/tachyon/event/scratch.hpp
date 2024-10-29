#pragma once

namespace yq::tachyon {
    struct KeyEvent {
        GLFWwindow* window;
        int         key;
        int         scancode;
        int         action;
        int         modifiers;
    };
    
    struct CharEvent {
        GLFWwindow*     window;
        unsigned int    codepoint;
    };
    
    struct CursorPositionEvent {
        GLFWwindow* window;
        double      xPos, yPos;
    };

    struct CursorEnterEvent {
        GLFWwindow* window;
        bool        entered;
    };
    
    struct MouseButtonEvent {
        GLFWwindow* window;
        int         button;
        int         action;
        int         mods;
    };
    
    struct ScrollEvent {
        GLFWwindow* window;
        double      xDelta, yDelta;
    };
    
    struct PathDropEvent {
        GLFWwindow*     window;
        int             count;
        const char**    paths;
    };
    
    struct MonitorConnectionEvent {
        Monitor         monitor;
        bool            connected;
    };
    
    struct JoystickConnectionEvent {
        Joystick        joystick;
        bool            connected;
    };
    
    struct JoystickStateEvent {
        Joystick                    joystick;
        std::vector<float>          axes;
        std::vector<unsigned char>  buttons;
        std::vector<unsigned char>  hats;
        
    };


#if 0
    enum class EventType : uint8_t {
        None            = 0x00,
        
        //  Key/Character Events 0x01xx
        
        System              = 0x10,
        
        Monitor             = 0x20,
        MonitorConnect      = 0x21,
        MonitorDisconnect   = 0x22,

        Window              = 0x30,
        WindowResize,
        WindowPathDrop,
        WindowCloseReq,
        WindowClose,
        WindowFocus,
        WindowMinimized,
        WindowMaximized,
        WindowRestored,
        WindowMoved,
        WindowRefresh,
        WindowScale,
        WindowFrameResize,

        Keyboard            = 0x40,
        KeyPress,
        KeyRelease          = 0x42,
        Character           = 0x43,
        
        Mouse               = 0x50,
        
        MousePress          = 0x51,
        MouseRelease        = 0x52,
        MouseMove           = 0x53,
        MouseEnter          = 0x54,
        MouseScroll         = 0x55,
        
        Joystick            = 0x60,
        JoystickConnect     = 0x61,
        JoystickDisconnect  = 0x62,
        JoystickState       = 0x63
    };

    // standard event types
    enum class EventBit : uint16_t {
    };
#endif}

