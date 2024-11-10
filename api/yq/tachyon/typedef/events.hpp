////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class AppEvent;
    class CursorCaptureEvent;
    class CursorDisableEvent;
    class CursorHideEvent;
    class CursorNormalEvent;
    class InputEvent;
    class JoystickAxisEvent;
    class JoystickConnectEvent;
    class JoystickDisconnectEvent;
    class JoystickEventInfo;
    class JoystickEvent;
    class JoystickHatEvent;
    class JoystickPressEvent;
    class JoystickReleaseEvent;
    class KeyboardEvent;
    class KeyCharacterEvent;
    class KeyPressEvent;
    class KeyReleaseEvent;
    class KeyRepeatEvent;
    class MonitorConnectEvent;
    class MonitorDisconnectEvent;
    class MonitorEventInfo;
    class MonitorEvent;
    class MouseCaptureEvent;
    class MouseDisableEvent;
    class MouseDropEvent;
    class MouseEnterEvent;
    class MouseEvent;
    class MouseHideEvent;
    class MouseLeaveEvent;
    class MouseMoveEvent;
    class MouseNormalEvent;
    class MousePressEvent;
    class MouseReleaseEvent;
    class MouseScrollEvent;
    class TachyonEvent;
    class ViewerCloseEvent;
    class ViewerEvent;
    class VulqanEvent;
    class WidgetEvent;
    class WindowDefocusEvent;
    class WindowDestroyEvent;
    class WindowEvent;
    class WindowFocusEvent;
    class WindowHideEvent;
    class WindowIconifyEvent;
    class WindowMaximizeEvent;
    class WindowMoveEvent;
    class WindowResizeEvent;
    class WindowRestoreEvent;
    class WindowScaleEvent;
    class WindowShowEvent;
    class WindowStateEvent;
    class WindowTitleEvent;

    using JoystickAxisEventCPtr         = Ref<const class JoystickAxisEvent>;
    using JoystickConnectEventCPtr      = Ref<const class JoystickConnectEvent>;
    using JoystickDisconnectEventCPtr   = Ref<const class JoystickDisconnectEvent>;
    using JoystickHatEventCPtr          = Ref<const class JoystickHatEvent>;
    using JoystickPressEventCPtr        = Ref<const class JoystickPressEvent>;
    using JoystickReleaseEventCPtr      = Ref<const class JoystickReleaseEvent>;
    using KeyCharacterEventCPtr         = Ref<const class KeyCharacterEvent>;
    using KeyPressEventCPtr             = Ref<const class KeyPressEvent>;
    using KeyReleaseEventCPtr           = Ref<const class KeyReleaseEvent>;
    using KeyRepeatEventCPtr            = Ref<const class KeyRepeatEvent>;
    using MonitorConnectEventCPtr       = Ref<const class MonitorConnectEvent>;
    using MonitorDisconnectEventCPtr    = Ref<const class MonitorDisconnectEvent>;
    using MouseCaptureEventCPtr         = Ref<const class MouseCaptureEvent>;
    using MouseDisableEventCPtr         = Ref<const class MouseDisableEvent>;
    using MouseDropEventCPtr            = Ref<const class MouseDropEvent>;
    using MouseEnterEventCPtr           = Ref<const class MouseEnterEvent>;
    using MouseHideEventCPtr            = Ref<const class MouseHideEvent>;
    using MouseLeaveEventCPtr           = Ref<const class MouseLeaveEvent>;
    using MouseMoveEventCPtr            = Ref<const class MouseMoveEvent>;
    using MouseNormalEventCPtr          = Ref<const class MouseNormalEvent>;
    using MousePressEventCPtr           = Ref<const class MousePressEvent>;
    using MouseReleaseEventCPtr         = Ref<const class MouseReleaseEvent>;
    using MouseScrollEventCPtr          = Ref<const class MouseScrollEvent>;
    using ViewerCloseEventCPtr          = Ref<const class ViewerCloseEvent>;
    using ViewerEventCPtr               = Ref<const class ViewerEvent>;
    using WindowDefocusEventCPtr        = Ref<const class WindowDefocusEvent>;
    using WindowDestroyEventCPtr        = Ref<const class WindowDestroyEvent>;
    using WindowEventCPtr               = Ref<const class WindowEvent>;
    using WindowFocusEventCPtr          = Ref<const class WindowFocusEvent>;
    using WindowHideEventCPtr           = Ref<const class WindowHideEvent>;
    using WindowIconifyEventCPtr        = Ref<const class WindowIconifyEvent>;
    using WindowMaximizeEventCPtr       = Ref<const class WindowMaximizeEvent>;
    using WindowResizeEventCPtr         = Ref<const class WindowResizeEvent>;
    using WindowRestoreEventCPtr        = Ref<const class WindowRestoreEvent>;
    using WindowScaleEventCPtr          = Ref<const class WindowScaleEvent>;
    using WindowShowEventCPtr           = Ref<const class WindowShowEvent>;
}
