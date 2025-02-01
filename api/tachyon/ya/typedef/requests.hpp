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
    class ViewerWidgetRequest;
    class WindowRequest;
    class WindowRefreshRequest;

    using CloseRequestCPtr          = Ref<const CloseRequest>;
    using ViewerWidgetRequestCPtr   = Ref<const ViewerWidgetRequest>;
    using WindowRefreshRequestCPtr  = Ref<const WindowRefreshRequest>;
}
