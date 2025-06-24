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
    class AppRequest;
    class CameraRequest;
    class CloseRequest;
    class TachyonRequest;
    class ViewerRequest;
    class SetWidgetRequest;
    class WindowRequest;
    class RefreshRequest;
    
    class ViewerScreenshotRequest;

    using CloseRequestCPtr              = Ref<const CloseRequest>;
    using SetWidgetRequestCPtr          = Ref<const SetWidgetRequest>;
    using SetRefreshRequestCPtr         = Ref<const RefreshRequest>;
    using ViewerScreenshotRequestCPtr   = Ref<const ViewerScreenshotRequest>;
}
