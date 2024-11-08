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
    template <typename V, typename A, typename ... Args> class ViManager;
    using ViBufferManager       = ViManager<const ViBuffer, Buffer>;
    using ViBufferManagerUPtr   = std::unique_ptr<ViBufferManager>;
}
