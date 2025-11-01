////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DebugRasters.hpp"
#include <yq/color/colors.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/raster/PatternRasters.hpp>
#include <yq/macro/debugrel.hpp>

namespace yq::tachyon::debug {
    RasterPtr  raster_missing()
    {
        static RasterPtr    s_ret   = checkerboard_raster(
            YQ_DBGREL(color::LimeGreen, color::DeepDarkGray), 
            YQ_DBGREL(color::Fuchsia, color::Gray),
            4
        );
        return s_ret;
    }
}

