////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gfx/Buffer.hpp>
#include <tachyon/typedef/buffer.hpp>

namespace yq::tachyon {

    //! Helper for buffer objects
    //! Simple helper to help with managing buffer objects, and spinning their results out
    template <BufferUsage::enum_t buf>
    struct BufferObject {
        BufferCPtr      buffer;
        
        //! Updates the memory buffer
        void    update(Memory&&mem)
        {
            buffer      = new Buffer(buf, std::move(mem));
        }
        
        //! Assigns the buffer object
        BufferObject& operator=(const BufferObject& obj)
        {
            buffer      = obj.buffer;
            return *this;
        }
        
        bool valid() const 
        { 
            return buffer.valid(); 
        }
        
        
    protected:
        BufferObject(){}
        ~BufferObject(){}
    };

    //! Vertex Buffer
    using VertexBuffer  = BufferObject<BufferUsage::Vertex>;
    
    //! Index Buffer
    using IndexBuffer   = BufferObject<BufferUsage::Index>;
    
    //! Uniform Buffer
    using UniformBuffer = BufferObject<BufferUsage::Uniform>;

    //! Storage Buffer
    using StorageBuffer = BufferObject<BufferUsage::Storage>;
}
