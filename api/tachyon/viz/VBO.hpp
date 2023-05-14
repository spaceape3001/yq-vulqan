////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/preamble.hpp>
#include <tachyon/preamble.hpp>
#include <tachyon/BufferArray.hpp>
#include <tachyon/BufferSpan.hpp>

namespace yq::tachyon {
    
    /*! \brief Array based buffer object
        
        Used for vertex & index, this is the common buffer object
    */
    template <typename T, BufferUsage::enum_t buf>
    struct ABO {
        BufferCPtr        buffer;
        
        ABO(){}
        ~ABO(){}
        
        ABO& operator=(std::span<const T> data)
        {
            buffer  = buffer_span(buf, data);
            return *this;
        }
        
        ABO& operator=(std::initializer_list<T> data)
        {
            buffer  = buffer_array(buf, span(data));
            return *this;
        }

        ABO& operator=(std::vector<T>&& data)
        {
            buffer  = buffer_array(buf, std::move(data));
            return *this;
        }
        
        ABO& operator=(const ABO& b)
        {
            buffer  = b.buffer;
            return *this;
        }
    };

    //! Buffer object with local data
    template <typename T, BufferUsage::enum_t buf>
    struct AB1 {
        BufferCPtr          buffer;
        std::vector<T>      data;
        
        AB1&   operator=(std::span<const T> data_)
        {
            data    = std::vector<T>(data_.begin(), data_.end());
            update();
            return *this;
        }
        
        AB1&   operator=(std::initializer_list<const T> data_)
        {
            data    = std::vector<T>(data_.begin(), data_.end());
            update();
            return *this;
        }

        AB1&   operator=(std::vector<T>&& data_)
        {
            data    = std::move(data_);
            update();
            return *this;
        }
        
        AB1&    operator=(const AB1& cp)
        {
            data    = cp.data;
            buffer  = cp.buffer;
            return *this;
        }
        
        AB1&    operator=(const ABO<T,buf>& b)
        {
            data    = {};
            buffer  = b.buffer;
            return *this;
        }
        
        operator ABO<T,buf>() const
        {
            return { buffer };
        }
        
        void    update()
        {
            buffer  = buffer_array(buf, data);
        }
    };

    //! Vertex buffer object
    template <typename T>  using VBO   = ABO<T,BufferUsage::Vertex>;
    
    //! Vertex buffer object (using span)
    template <typename T>  using VB1   = AB1<T,BufferUsage::Vertex>;

    //! Index buffer object
    template <typename T>  using IBO   = ABO<T,BufferUsage::Index>;

    //! Index buffer object (using span)
    template <typename T>  using IB1   = AB1<T,BufferUsage::Index>;
}
