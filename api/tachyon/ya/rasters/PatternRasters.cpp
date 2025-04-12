////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PatternRasters.hpp"
#include <yt/gfx/Raster.hpp>
#include <yq/raster/Pixels.hxx>
#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    RasterPtr   checkerboard_raster(RGBA4U8 a, RGBA4U8 b, unsigned half)
    {
        unsigned size   = half * half;
        Pixels2<RGBA4U8>  pixels({size, size}, a);
        for(unsigned r=0;r<half;++r)
            for(unsigned c=0;c<half;++c)
        {

            pixels.set({half+r,c}, b);
            pixels.set({r,c+half}, b);
        }
        
        return new Raster(COPY, pixels);
    }
    
    RasterPtr   checkerboard_raster(RGB3U8 a, RGB3U8 b, unsigned half)
    {
        return checkerboard_raster(rgba(a, 255), rgba(b, 255));
    }
}

