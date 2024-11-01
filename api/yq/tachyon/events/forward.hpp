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
    using ViewerDefocusEventCPtr        = Ref<const class ViewerDefocusEvent>;
    using ViewerEventCPtr               = Ref<const class ViewerEvent>;
    using ViewerFocusEventCPtr          = Ref<const class ViewerFocusEvent>;
    using ViewerIconifyEventCPtr        = Ref<const class ViewerIconifyEvent>;
    using ViewerMaximizeEventCPtr       = Ref<const class ViewerMaximizeEvent>;
    using ViewerResizeEventCPtr         = Ref<const class ViewerResizeEvent>;
    using ViewerRestoreEventCPtr        = Ref<const class ViewerRestoreEvent>;
    using ViewerScaleEventCPtr          = Ref<const class ViewerScaleEvent>;
}
