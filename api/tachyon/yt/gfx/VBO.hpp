////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/gfx/BufferObject.hpp>
#include <yq/container/vector_utils.hpp>

namespace yq::tachyon {
    
    
    /*! Array-based buffer without storage
    */
    template <typename T, BufferUsage::enum_t BUF>
    struct ABO : public BufferObject<BUF> {
        static_assert(std::is_trivial_v<T>, "T should be trivial");
    
        ABO(){}
        ~ABO(){}
        
        //! Created buffer from static data
        template <size_t N>
        ABO( const T(&ptr)[N] )
        {
            BufferObject<BUF>::update(Memory(REF, ptr));
        }
        
        //! Proxy for span & data
        template <typename K>
        struct ProxyI {
            ABO *abo;
            
            //! Assigns by span
            ABO& operator, (std::span<const T> values)
            {
                abo->BufferObject<BUF>::update(Memory(K(), values));
                return *abo;
            }
            
            //! Assigns by reference
            template <size_t N>
            ABO& operator, (const T (&ptr)[N])
            {
                abo->BufferObject<BUF>::update(Memory(K(), ptr));
                return *abo;
            }
        };

        //! Used for assigning by copy
        ProxyI<copy_k>   operator=(copy_k)
        {
            return { this };
        }
        
        //! Used by assigning by reference
        ProxyI<ref_k>   operator=(ref_k)
        {
            return { this };
        }
        
        //! Used for assigning by initializer list
        ABO&        operator=(std::initializer_list<const T> data)
        {
            BufferObject<BUF>::update(Memory(COPY, span(data)));
            return *this;
        }
    };
    
    /*! Array-based buffer with storage
    */
    template <typename T, BufferUsage::enum_t BUF>
    struct AB1 : public BufferObject<BUF> {
        static_assert(std::is_trivial_v<T>, "T should be trivial");

        std::vector<T>      data;
        
        AB1(){}
        
        //! Creates by initialier list
        AB1(std::initializer_list<const T> data_) : data(data_.begin(), data_.end())
        {
            update();
        }
        
        //! Default copy operator
        AB1&    operator=(const AB1&) = default;
        
        //! Copy from ABO (note, data will not be filled)
        AB1&    operator=(const ABO<T,BUF>& cp)
        {
            data.clear();
            BufferObject<BUF>::buffer = cp.buffer;
            //update();
            return *this;
        }
        
        //! Copy from span into data and buffer
        AB1&   operator=(std::span<const T> data_)
        {
            data    = std::vector<T>(data_.begin(), data_.end());
            update();
            return *this;
        }
        
        //! Copy from initializer list into data and buffer
        AB1&   operator=(std::initializer_list<const T> data_)
        {
            data    = std::vector<T>(data_.begin(), data_.end());
            update();
            return *this;
        }

        //! Moves data into buffer
        AB1&   operator=(std::vector<T>&& data_)
        {
            data    = std::move(data_);
            update();
            return *this;
        }
        
        //! Updates the buffer memory
        void    update()
        {
            BufferObject<BUF>::update(Memory(COPY,span(data)));
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
