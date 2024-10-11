////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/memory/BufferObject.hpp>

namespace yq::tachyon {


    
    /*! Uniform buffer object
    
        This is a uniform buffer object whose data is either set once or
        it lives elsewhere.
    */
    template <typename T>
    struct UBO : public UniformBuffer {
        UBO(){}
        ~UBO(){}
        
        // Only create by UBO
        struct RefProxy {
            UBO*        ubo;
            UBO&    operator, (const T& value)
            {
                ubo->UniformBuffer::update(Memory(REF1, value));
                return *ubo;
            }
            UBO&    operator, (const T* value)
            {
                ubo->UniformBuffer::update(Memory(REF1, *value));
                return *ubo;
            }
            UBO&    operator, (T&& value) = delete;
        };
        
        // Only create by UBO
        struct CopyProxy {
            UBO*    ubo;
            UBO&    operator, (const T& value)
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
    struct UB1 : public UniformBuffer {
        T               data        = {};
        
        UB1(){}
        ~UB1(){}
        
        //! Copies the data into a buffer, prepped for the GPU
        void        update()
        {
            UniformBuffer::update(Memory(COPY1, data));
        }
        
        UB1& operator=(const UB1&) = default;
        UB1& operator=(const UBO<T>&cp)
        {
            data    = {};
            UniformBuffer::buffer   = cp.UniformBuffer::buffer;
            return *this;
        }
        
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
    };
}
