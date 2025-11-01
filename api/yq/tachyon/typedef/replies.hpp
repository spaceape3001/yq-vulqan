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
    class AppReply;
    class CameraReply;
    class TachyonRequest;
    class TachyonReply;
    class ViewerCloseReply;
    class ViewerRequest;
    class ViewerReply;
    class ViewerWidgetReply;

    using ViewerCloseReplyCPtr  = Ref<const class ViewerCloseReply>;
}
