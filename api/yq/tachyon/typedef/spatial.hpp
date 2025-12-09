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
    class Spatial;
    using SpatialPtr      = Ref<Spatial>;
    using SpatialCPtr     = Ref<const Spatial>;

    struct SpatialSnap;
    using SpatialSnapPtr  = Ref<SpatialSnap>;
    using SpatialSnapCPtr = Ref<const SpatialSnap>;
    
    struct SpatialData;
    using SpatialDataPtr  = Ref<SpatialData>;
    using SpatialDataCPtr = Ref<const SpatialData>;

    template <class> class ID;
    using SpatialID = ID<Spatial>;
    
    class SpatialMeta;

    template <class E>
    concept SomeSpatial = std::derived_from<E,Spatial>;
}
