////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>
namespace yq::tachyon {
    class Buffer;
    class ViBuffer;
    template <typename V, typename A, typename ... Args> class ViManager2;
    using ViBufferManager       = ViManager2<const ViBuffer, Buffer>;
    using ViBufferManagerUPtr   = std::unique_ptr<ViBufferManager>;
}
