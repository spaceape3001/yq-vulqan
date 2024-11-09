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
    class GLFWCloseCommand;
    class GLFWCommand;
    class GLFWHideCommand;
    class GLFWShowCommand;
    class MouseCaptureCommand;
    class MouseCommand;
    class MouseDisableCommand;
    class MouseHideCommand;
    class MouseNormalCommand;
    class TachyonCommand;
    class ViewerAttentionCommand;
    class ViewerCloseCommand;
    class ViewerCommand;
    class ViewerHideCommand;
    class ViewerIconifyCommand;
    class ViewerMaximizeCommand;
    class ViewerPauseCommand;
    class ViewerRestoreCommand;
    class ViewerResumeCommand;
    class ViewerShowCommand;
    class WindowAttentionCommand;
    class WindowCommand;
    class WindowDestroyCommand;
    class WindowFocusCommand;
    class WindowHideCommand;
    class WindowIconifyCommand;
    class WindowMaximizeCommand;
    class WindowMoveCommand;
    class WindowRestoreCommand;
    class WindowShowCommand;

    using MouseCaptureCommandCPtr       = Ref<const class MouseCaptureCommand>;
    using MouseDisableCommandCPtr       = Ref<const class MouseDisableCommand>;
    using MouseHideCommandCPtr          = Ref<const class MouseHideCommand>;
    using MouseNormalCommandCPtr        = Ref<const class MouseNormalCommand>;

    using ViewerAttentionCommandCPtr    = Ref<const class ViewerAttentionCommand>;
    using ViewerCloseCommandCPtr        = Ref<const class ViewerCloseCommand>;
    using ViewerHideCommandCPtr         = Ref<const class ViewerHideCommand>;
    using ViewerIconifyCommandCPtr      = Ref<const class ViewerIconifyCommand>;
    using ViewerMaximizeCommandCPtr     = Ref<const class ViewerMaximizeCommand>;
    using ViewerPauseCommandCPtr        = Ref<const class ViewerPauseCommand>;
    using ViewerRestoreCommandCPtr      = Ref<const class ViewerRestoreCommand>;
    using ViewerResumeCommandCPtr       = Ref<const class ViewerResumeCommand>;
    using ViewerShowCommandCPtr         = Ref<const class ViewerShowCommand>;
}
