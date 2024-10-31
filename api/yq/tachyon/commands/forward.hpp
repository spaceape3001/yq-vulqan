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
    using ViewerAttentionCommandCPtr    = Ref<const class ViewerAttentionCommand>;
    using ViewerCloseCommandCPtr        = Ref<const class ViewerCloseCommand>;
    using ViewerHideCommandCPtr         = Ref<const class ViewerHideCommand>;
    using ViewerIconifyCommandCPtr      = Ref<const class ViewerIconifyCommand>;
    using ViewerMaximizeCommandCPtr     = Ref<const class ViewerMaximizeCommand>;
    using ViewerPauseCommandCPtr        = Ref<const class ViewerPauseCommand>;
    using ViewerRestoreCommandCPtr      = Ref<const class ViewerRestoreCommand>;
    using ViewerResumeCommandCPtr       = Ref<const class ViewerResumeCommand>;
}
