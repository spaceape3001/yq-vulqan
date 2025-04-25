////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/cursor.hpp>
#include <tachyon/typedef/joystick.hpp>
#include <tachyon/typedef/monitor.hpp>
#include <tachyon/typedef/window.hpp>

#include <array>
#include <map>
#include <vector>

#include <GLFW/glfw3.h>

struct GLFWcursor;
struct GLFWmonitor;
struct GLFWwindow;

namespace yq::tachyon {
    class CursorGLFW;
    using glfw_cursor_map       = std::map<CursorID, CursorGLFW*>;
    
    class DesktopGLFW;
    
    static constexpr const int   kCntGLFWJoysticks   = GLFW_JOYSTICK_LAST + 1;
    class JoystickGLFW;
    class GamepadGLFW;
    using glfw_joystick_map     = std::map<JoystickID, JoystickGLFW*>;
    using glfw_joystick_array   = std::array<JoystickGLFW*, kCntGLFWJoysticks>;
    using glfw_gamepad_array    = std::array<GamepadGLFW*, kCntGLFWJoysticks>;
    
    class KeyboardGLFW;
    class MonitorGLFW;
    using glfw_monitor_map      = std::map<MonitorID, MonitorGLFW*>;

    class MouseGLFW;

    class WindowGLFW;
    using glfw_window_map       = std::map<WindowID, WindowGLFW*>;
}
