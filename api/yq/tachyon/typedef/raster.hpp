////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Raster;
    using RasterPtr              = Ref<Raster>;
    using RasterCPtr             = Ref<const Raster>;

    template <class> class ID;
    
    using RasterID = ID<Raster>;
}
