////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <tachyon/BufferCopy.hpp>

namespace yq::tachyon {
    
    /*! Uniform buffer object
    
        This is a uniform buffer object whose data is either set once or
        it lives elsewhere.
    */
    template <typename T>
    struct UBO {
        BufferCPtr      buffer;
    
        UBO(){}
        ~UBO(){}
    
        UBO&    operator=(const T& value)
        {
            buffer  = buffer_copy(BufferUsage::Uniform, value);
            return *this;
        }

        UBO&    operator=(T&& value)
        {
            buffer  = buffer_copy(BufferUsage::Uniform, std::move(value));
            return *this;
        }
        
        UBO&    operator=(const UBO& b)
        {
            buffer  = b.buffer;
            return *this;
        }
    };

    /*! \brief Uniform buffer with storage
    
        This is a uniform buffer object whose data copy lives here.
        Call "update" after modification.  (note, a copy in will trigger the update)
    */
    template <typename T>
    struct UB1 {
        BufferCPtr      buffer;
        T               data        = {};
        
        UB1(){}
        
        UB1& operator=(const T& data_)
        {
            data    = data_;
            update();
            return *this;
        }
        
        UB1& operator=(T&& data_)
        {
            data    = std::move(data_);
            update();
            return *this;
        }
        
        UB1& operator=(const UBO<T>& b)
        {
            data    = {};
            buffer  = b.buffer;
            return *this;
        }

        //! Clobbers the buffer, uses the other buffer until modified
        UB1& operator=(const UB1<T>& b)
        {
            data    = b.data;
            buffer  = b.buffer;
            return *this;
        }

        operator UBO<T>() const { return { buffer }; }

        void    update()
        {
            buffer  = buffer_copy(BufferUsage::Uniform, data);
        }
    };


}
