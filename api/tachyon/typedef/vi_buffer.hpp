////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/buffer.hpp>
#include <variant>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class ViBuffer;
    using ViBufferPtr           = Ref<ViBuffer>;
    using ViBufferCPtr          = Ref<const ViBuffer>;

    using Buffered              = std::variant<std::monostate, BufferCPtr, ViBufferCPtr>;
}
