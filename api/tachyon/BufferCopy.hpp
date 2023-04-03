////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Buffer.hpp>
#include <type_traits>

namespace yq {
    namespace tachyon {

        /*! Buffer as a single item
        */
        template <typename T>
        class BufferCopy : public Buffer {
        public:

            BufferCopy(BufferUsageFlags buf, const T& cp) : Buffer(buf), m_data(cp) 
            {
                push();
            }
            
            BufferCopy(BufferUsageFlags buf, T&& mv) : Buffer(buf), m_data(std::move(mv)) 
            {
                push();
            }
            
        private:
            virtual ~BufferCopy(){}
            
            void    push()
            {
                m_pointer   = &m_data;
                m_size      = sizeof(T);
            }

            const T         m_data;
        };    

        template <typename T>
        Ref<const Buffer>   buffer_copy(BufferUsageFlags buf, T&& val)
        {
            using U     = std::decay<T>::type;
            if constexpr (std::is_rvalue_reference_v<T>){
                return new BufferCopy<U>(buf, std::move(val));
            } else {
                return new BufferCopy<U>(buf, val);
            }
        }
    }
}
