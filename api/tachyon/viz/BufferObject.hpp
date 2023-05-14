////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <tachyon/viz/Buffer.hpp>

namespace yq::tachyon {

    template <BufferUsage::enum_t buf>
    struct BufferObject {
        BufferCPtr      buffer;
        
        void    update(Memory&&mem)
        {
            buffer      = new Buffer(buf, std::move(mem));
        }
        
        BufferObject& operator=(const BufferObject& obj)
        {
            buffer      = obj.buffer;
            return *this;
        }
        
        
    protected:
        BufferObject(){}
        ~BufferObject(){}
    };

    using VertexBuffer  = BufferObject<BufferUsage::Vertex>;
    using IndexBuffer   = BufferObject<BufferUsage::Index>;
    using UniformBuffer = BufferObject<BufferUsage::Uniform>;
}
