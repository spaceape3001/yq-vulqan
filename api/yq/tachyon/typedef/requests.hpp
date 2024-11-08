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
    class ViewerCloseRequest;
    class ViewerRefreshRequest;
    class ViewerRequest;

    using ViewerCloseRequestCPtr    = Ref<const class ViewerCloseRequest>;
    using ViewerRefreshRequestCPtr  = Ref<const class ViewerRefreshRequest>;
}
