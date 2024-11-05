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
    using ViewerCloseRequestCPtr    = Ref<const class ViewerCloseRequest>;
    using ViewerRefreshRequestCPtr  = Ref<const class ViewerRefreshRequest>;
}