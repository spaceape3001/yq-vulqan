////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/preamble.hpp>
#include <basic/keywords.hpp>
#include <tachyon/preamble.hpp>
#include <tachyon/viz/BufferObject.hpp>

namespace yq::tachyon {
    
    
    /*! Array-based buffer without storage
    
    
    */
    template <typename T, BufferUsage::enum_t BUF>
    struct ABO : public BufferObject<BUF> {
        static_assert(std::is_trivial_v<T>, "T should be trivial");
    
        ABO(){}
        ~ABO(){}
        
        template <size_t N>
        ABO( const T(&ptr)[N] )
        {
            BufferObject<BUF>::update(Memory(REF, ptr));
        }
        
        template <typename K>
        struct Proxy {
            ABO *abo;
            ABO& operator, (std::span<const T> values)
            {
                abo->BufferObject<BUF>::update(Memory(K(), values));
                return *abo;
            }
            
            template <size_t N>
            ABO& operator, (const T (&ptr)[N])
            {
                abo->BufferObject<BUF>::update(Memory(K(), ptr));
                return *abo;
            }
        };

        Proxy<copy_t>   operator=(copy_t)
        {
            return { this };
        }
        
        Proxy<ref_t>   operator=(ref_t)
        {
            return { this };
        }
        
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
        AB1(std::initializer_list<const T> data_) : data(data_.begin(), data_.end())
        {
            update();
        }
        
        AB1&    operator=(const AB1&) = default;
        
        AB1&    operator=(const ABO<T,BUF>& cp)
        {
            data.clear();
            update();
            return *this;
        }
        
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
