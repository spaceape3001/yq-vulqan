////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class ViBuffer;
    using ViBufferPtr           = Ref<ViBuffer>;
    using ViBufferCPtr          = Ref<const ViBuffer>;
}
