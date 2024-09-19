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
    class ViThread;
    using ViThreadPtr           = Ref<ViThread>;
    using ViThreadCPtr          = Ref<const ViThread>;
}
