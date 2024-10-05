////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/pixels/Pixmap.hpp>

#include <yq-toolbox/meta/Coord.hpp>
#include <yq-toolbox/meta/Coord1.hpp>
#include <yq-toolbox/meta/Coord2.hpp>
#include <yq-toolbox/meta/Coord3.hpp>
#include <yq-toolbox/meta/Coord4.hpp>
#include <yq-toolbox/meta/Coord5.hpp>
#include <yq-toolbox/meta/Coord6.hxx>
#include <yq-toolbox/meta/InfoBinder.hpp>


namespace yq::tachyon {
    template <uint8_t DIMS, class C>
    struct Pixels : public PixmapN<DIMS>, public pixel::array<N,C> {
    
        static_assert(DIMS && (DIMS<=6), "Pixel dimensions limited 1 to 6");
        static_assert(is_type_v<C>, "Pixel data must be meta-capable!  (Missing a declare macro?)");
    
        using coord_t                           = pixel::coord<DIMS>;
        using array_t                           = pixel::array<DIMS,C>;
        using color_t                           = C;
        static constexpr uint8_t  kDimensions   = DIMS;
        using array_t::count;

        static coord_t     coord(std::span<const index_t> pix) const
        {
            coord_t ret;
            for(uint8_t n=0;n<kDimensions;++n){
                if(pix.size() > n){
                    set(ret, n, pix[n]);
                } else {
                    set(ret, n, 0);
                }
            }
            return ret;
        }

        size_t                      bytes(pixel_t) const override
        { 
            return sizeof(C);
        }
        
        size_t                      bytes(total_t) const override
        {
            return count(PIXELS) * sizeof(C);
        }
        
        uint8_t                     count(dimensions_t) const override
        {
            return kDimensions;
        }
        
        size_t                      count(i_t) const override
        {
            return count().i;
        }
        
        size_t                      count(j_t) const override
        {
            if constexpr (kDimensions >= 2){
                return count().j;
            } else {
                return 0ULL;
            }
        }
        
        size_t                      count(k_t) const override
        {
            if constexpr (kDimensions >= 3){
                return count().k;
            } else {
                return 0ULL;
            }
        }
        
        size_t                      count(l_t) const override
        {
            if constexpr (kDimensions >= 4){
                return count().l;
            } else {
                return 0ULL;
            }
        }
        
        size_t                      count(m_t) const override
        {
            if constexpr (kDimensions >= 5){
                return count().m;
            } else {
                return 0ULL;
            }
        }
        
        size_t                      count(n_t) const override
        {
            if constexpr (kDimensions >= 6){
                return count().k;
            } else {
                return 0ULL;
            }
        }
        
        size_t  count(pixels_t) const override
        {
            coord_t     cc  = count();
            size_t      ret = cc.i;
            
            if constexpr (kDimensions >= 2){
                ret *= cc.j;
            }
            if constexpr (kDimensions >= 3){
                ret *= cc.k;
            }
            if constexpr (kDimensions >= 4){
                ret *= cc.l;
            }
            if constexpr (kDimensions >= 5){
                ret *= cc.m;
            }
            if constexpr (kDimensions >= 6){
                ret *= cc.n;
            }
            return ret;
        }

        bool                        empty() const override
        {
            return array_t::empty();
        }

        Any                 get(const coord_t& cc) const override
        {
            return Any(pixel(cc));
        }
        
        Any                 get(std::span<const index_t> pix) const override
        {
            return get(coord(pix));
        }

        std::span<const index_t>    dimensions() const override
        {
            static thread_local index_t ret[N];
            coord_t             cc  = count();
            for(uint8_t n=0;n<kDimensions;++n){
                ret[n] = get(cc, n);
            }
            return ret;
        }
        
        C                           pixel(const coord_t& coord) const 
        {
            if(any(coord) >= count())
                return C{};
            return array_t::get(coord);
        }

        const void*                 pointer(data_t) const override
        {
            return data();
        }

        virtual bool                set(const coord_t& cc, const Any& val) override
        {
            if(any(cc) >= count())
                return false;

            static const auto&  kMeta   = meta<C>();
            static const auto   kId     = kMeta.id();

            const TypeInfo&     type    = val.type();
            const void*         ptr     = val.unsafe_ptr();
            
            if(type.id() == kId){
                edit(cc) = *(const C*) ptr;
            } else {
                TypeInfo::FNConverter   cvt = type.converter(kMeta);
                if(!cvt)
                    return false;
                cvt(&edit(cc), ptr);
            }
            return true;
        }

        virtual bool                set(std::span<const index_t> pix, const Any& val) override
        {
            return set(coord(pix), val);
        }
        
        bool    set(const coord_t& cc, const C& val) 
        {
            if(any(cc) >= count())
                return false;
            edit(cc) = val;
            return true;
        }

        const TypeInfo&             type(pixel_t) const override
        {
            return meta<T>();
        }
    };
}
