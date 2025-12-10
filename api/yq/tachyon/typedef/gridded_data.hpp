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
    class GriddedData;
    using GriddedDataPtr              = Ref<GriddedData>;
    using GriddedDataCPtr             = Ref<const GriddedData>;

    template <class> class ID;
    
    using GriddedDataID = ID<GriddedData>;
}
