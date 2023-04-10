////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Buffer.hpp>

namespace yq::tachyon {

    /*! Buffer as a span
    
        \note This data *MUST* live for the duration of this pointer.
    */
    template <typename T>
    class BufferSpan : public Buffer {
    public:
    
        BufferSpan(BufferUsageFlags buf, std::span<const T> cp) : Buffer(buf)
        {
            m_pointer   = cp.data();
            m_size      = sizeof(T) * cp.size();
        }
        
    private:
        virtual ~BufferSpan()
        {
        }
    };    
    
    template <typename T>
    Ref<const Buffer> buffer_span(BufferUsageFlags buf, std::span<const T> data)
    {
        return new BufferSpan<T>(buf, data);
    }
}
