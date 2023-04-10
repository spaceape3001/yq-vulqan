////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Buffer.hpp>
#include <vector>
#include <span>

namespace yq::tachyon {

    /*! \brief Buffer as a vector of data
    
        This is a buffer for an ARRAY of data.
    */
    template <typename T>
    class BufferArray : public Buffer {
    public:

        BufferArray(BufferUsageFlags buf, std::span<const T> cp) : Buffer(buf), m_data(cp.begin(), cp.end()) 
        {
            push();
        }
        
        BufferArray(BufferUsageFlags buf, std::vector<T>&& mv) : Buffer(buf), m_data(std::move(mv)) 
        {
            push();
        }

    private:
        void    push() 
        {
            m_pointer   = m_data.data();
            m_size      = m_data.size() * sizeof(T);
        }
        
        ~BufferArray()
        {
        }
        
        std::vector<T>              m_data;
    };
    
    template <typename T>
    Ref<const Buffer>   buffer_array(BufferUsageFlags buf, std::span<const T> cp)
    {
        return new BufferArray<T>(buf, cp);
    }

    template <typename T>
    Ref<const Buffer>   buffer_array(BufferUsageFlags buf, std::vector<T>&& mv)
    {
        return new BufferArray<T>(buf, std::move(mv));
    }
}
