////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Raster;
    
    using RasterPtr              = Ref<Raster>;
    using RasterCPtr             = Ref<const Raster>;
}
