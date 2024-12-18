////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/buffer/Buffer.hpp>

namespace yq::tachyon {
    Buffer::Buffer(BufferUsageFlags buf, Memory&& mem) : memory(std::move(mem)), usage(buf)
    {
    }
    
    Buffer::~Buffer()
    {
    }
    
}
