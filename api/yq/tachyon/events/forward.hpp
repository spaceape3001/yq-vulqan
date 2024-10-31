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
    using ViewerEventCPtr           = Ref<const class ViewerEvent>;
    using ViewerCloseEventCPtr      = Ref<const class ViewerCloseEvent>;
    using ViewerResizeEventCPtr     = Ref<const class ViewerResizeEvent>;
}
