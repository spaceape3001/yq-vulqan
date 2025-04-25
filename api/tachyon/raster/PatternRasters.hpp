////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/raster.hpp>
#include <yq/typedef/rgb.hpp>
#include <yq/typedef/rgba.hpp>

namespace yq::tachyon {
    RasterPtr   checkerboard_raster(RGB3U8 a, RGB3U8 b, unsigned half=2);
    RasterPtr   checkerboard_raster(RGBA4U8 a, RGBA4U8 b, unsigned half=2);
}

