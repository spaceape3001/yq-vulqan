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
    class ViFrame;
    using ViFramePtr           = Ref<ViFrame>;
    using ViFrameCPtr          = Ref<const ViFrame>;
}
