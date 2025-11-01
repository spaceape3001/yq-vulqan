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
    class AppCommand;
    class CameraCommand;
    class ControllerCommand;
    class MouseCaptureCommand;
    class MouseCommand;
    class MouseDisableCommand;
    class MouseHideCommand;
    class MouseNormalCommand;
    class TachyonCommand;
    class TachyonProxyCommand;
    class TachyonRemoveCommand;
    class TachyonThreadCommand;
    class ViewerCommand;
    class ViewerCursorCaptureCommand;
    class ViewerCursorDisableCommand;
    class ViewerCursorHideCommand;
    class ViewerCursorNormalCommand;
    class ViewerTitleCommand;
    class WindowAttentionCommand;
    class WindowCommand;
    class WindowCursorCaptureCommand;
    class WindowCursorDisableCommand;
    class WindowCursorHideCommand;
    class WindowCursorNormalCommand;
    class WindowDestroyCommand;
    class WindowTitleCommand;
    
    class ViewerCreateCommand;
    
    using ViewerCreateCommandCPtr   = Ref<const ViewerCreateCommand>;
}
