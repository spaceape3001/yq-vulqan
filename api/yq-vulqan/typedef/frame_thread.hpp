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
    class ViFrameThread;
    using ViFrameThreadPtr           = Ref<ViFrameThread>;
    using ViFrameThreadCPtr          = Ref<const ViFrameThread>;
}
