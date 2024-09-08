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
    class Buffer;
    using BufferCPtr    = Ref<const Buffer>;
    
    class ViBuffer;
    using ViBufferPtr   = Ref<ViBuffer>;
    using ViBufferCPtr  = Ref<const ViBuffer>;

    class ViBufferManager;
}
