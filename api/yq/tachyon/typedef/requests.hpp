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
    class TachyonRequest;
    class ViewerRequest;
    class ViewerCloseRequest;
    class ViewerWidgetRequest;
    class WindowRequest;
    class WindowRefreshRequest;

    using ViewerCloseRequestCPtr    = Ref<const ViewerCloseRequest>;
    using ViewerWidgetRequestCPtr   = Ref<const ViewerWidgetRequest>;
    using WindowRefreshRequestCPtr  = Ref<const WindowRefreshRequest>;
}
