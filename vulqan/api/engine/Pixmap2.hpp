////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Pixmap.hpp"
#include <basic/Array.hpp>
#include <engine/render/PipelineUtils.hpp>

namespace yq {
    namespace engine {
    
        template <typename T>
        class Pixmap2 : public Pixmap {
        public:
            Array2<T>       m_pixels;
            
            using COORD         = typename Array2<T>::coord_type;
            using index_type    = typename Array2<T>::index_type;
        
            Pixmap2() 
            {
                m_format    = data_format<T>();
            }
            
            Pixmap2(index_type w, index_type h) : Pixmap2()
            {
                m_pixels.set_counts({w,h});
                m_pixels.build();
            }
            
            ImageType   image_type() const override
            {
                return ImageType::Is2D;
            }
            
            std::span<std::byte>    data() const override
            {
                return std::span<std::byte>( (const std::byte*) m_pixels.data(), m_pixels.total_bytes());
            }
            
            uint8_t  dims() const override
            {
                return 2;
            }

            size_t  height() const override
            { 
                return (size_t) m_pixels.count().y; 
            }

            size_t  pixel_count() const override
            {
                return m_pixels.total();
            }

            size_t  pixel_size() const 
            {
                return sizeof(T);
            }
            
            size_t  width() const override 
            { 
                return (size_t) m_pixels.count().x; 
            }
        };
    
    };
}
