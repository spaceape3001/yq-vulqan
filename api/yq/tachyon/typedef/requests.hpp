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
    class TachyonRequest;
    class ViewerRequest;
    class ViewerCloseRequest;
    class ViewerWidgetRequest;
    class WindowRequest;
    class WindowCloseRequest;
    class WindowRefreshRequest;

    using ViewerCloseRequestCPtr    = Ref<const ViewerCloseRequest>;
    using ViewerWidgetRequestCPtr   = Ref<const ViewerWidgetRequest>;
    using WindowCloseRequestCPtr    = Ref<const WindowCloseRequest>;
    using WindowRefreshRequestCPtr  = Ref<const WindowRefreshRequest>;
}
