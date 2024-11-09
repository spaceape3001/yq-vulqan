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
    class WindowRequest;
    class ViewerCloseRequest;
    class WindowRefreshRequest;

    using ViewerCloseRequestCPtr    = Ref<const class ViewerCloseRequest>;
    using WindowRefreshRequestCPtr  = Ref<const class WindowRefreshRequest>;
}
