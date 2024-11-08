////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/buffer/BufferObject.hpp>

namespace yq::tachyon {


    
    /*! Uniform buffer object
    
        This is a uniform buffer object whose data is either set once or
        it lives elsewhere.
    */
    template <typename T>
    struct SBO : public UniformBuffer {
        SBO(){}
        ~SBO(){}
        
        // Only create by SBO
        struct RefProxy {
            SBO*        ubo;
            SBO&    operator, (const T& value)
            {
                ubo->UniformBuffer::update(Memory(REF1, value));
                return *ubo;
            }
            SBO&    operator, (const T* value)
            {
                ubo->UniformBuffer::update(Memory(REF1, *value));
                return *ubo;
            }
            SBO&    operator, (T&& value) = delete;
        };
        
        // Only create by SBO
        struct CopyProxy {
            SBO*    ubo;
            SBO&    operator, (const T& value)
            {
                ubo->UniformBuffer::update(Memory(COPY1, value));
                return *ubo;
            }
        };
        
        RefProxy    operator=(ref_t)
        {
            return { this };
        }

        CopyProxy    operator=(copy_t)
        {
            return { this };
        }
    };

    /*! \brief Uniform buffer with storage
    
        This is a uniform buffer object whose data copy lives here.
        Call "update" after modification.  (note, a copy in will trigger the update)
    */
    template <typename T>
    struct SB1 : public UniformBuffer {
        T               data        = {};
        
        SB1(){}
        ~SB1(){}
        
        //! Copies the data into a buffer, prepped for the GPU
        void        update()
        {
            UniformBuffer::update(Memory(COPY1, data));
        }
        
        SB1& operator=(const SB1&) = default;
        SB1& operator=(const SBO<T>&cp)
        {
            data    = {};
            UniformBuffer::buffer   = cp.UniformBuffer::buffer;
            return *this;
        }
        
        SB1& operator=(const T& data_)
        {
            data    = data_;
            update();
            return *this;
        }
        
        SB1& operator=(T&& data_)
        {
            data    = std::move(data_);
            update();
            return *this;
        }
    };
}
