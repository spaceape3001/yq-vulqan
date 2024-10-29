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
    class Buffer;
    using BufferCPtr            = Ref<const Buffer>;
    
    class ViBuffer;
    using ViBufferPtr           = Ref<ViBuffer>;
    using ViBufferCPtr          = Ref<const ViBuffer>;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViBufferManager       = ViManager<const ViBuffer, Buffer>;
    using ViBufferManagerUPtr   = std::unique_ptr<ViBufferManager>;
}
