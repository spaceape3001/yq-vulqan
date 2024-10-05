////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


#include <yq-toolbox/container/Array.hpp>

#include <yq-vulqan/keywords.hpp>
#include <yq-vulqan/data/DataFormat.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq-vulqan/typedef/pixmap.hpp>

namespace yq::tachyon {
    class Pixmap {
    public:
        using index_t  = pixel::index_t;

        virtual size_t                      bytes(pixel_t) const = 0;
        virtual size_t                      bytes(total_t) const = 0;
        
        virtual uint8_t                     count(dimensions_t) const = 0;
        virtual size_t                      count(i_t) const = 0;
        virtual size_t                      count(j_t) const = 0;
        virtual size_t                      count(k_t) const = 0;
        virtual size_t                      count(l_t) const = 0;
        virtual size_t                      count(m_t) const = 0;
        virtual size_t                      count(n_t) const = 0;
        virtual size_t                      count(pixels_t) const = 0;
        
        virtual bool                        empty() const = 0;
        
        virtual const void*                 pointer(data_t) const = 0;

        //  Note, this data will be thread-local temporary until next call on thread, so copy if persistence is desired!
        virtual std::span<const index_t>    dimensions() const = 0;

        virtual const TypeInfo&             type(pixel_t) const = 0;
        
        virtual Any                         get(std::span<const index_t>) const = 0;
        
        virtual bool                        set(std::span<const index_t>, const Any&) = 0;
        
        virtual ~Pixmap();
        
    protected:
        Pixmap();
    };
    

    
    template <uint8_t DIMS>
    class PixmapN : public Pixmap {
    public:
        
        using coord_t                           = pixel::coord<DIMS>;

        using Pixmap::get;
        
        virtual Any     get(const coord_t&) const = 0;
        
        using Pixmap::set;
        virtual bool    set(const coord_t&, const Any&) = 0;
    };
    
    
    #if 0    
        //! Governs lookups
        enum class Edge : uint8_t {
            Zero,
            Clamp,
            Extrapolate,
            Mirror,
            Repeat,
            MirrorRepeat
        };
    #endif

}

