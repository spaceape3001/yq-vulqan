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
    class Layer;
    using LayerPtr      = Ref<Layer>;
    using LayerCPtr     = Ref<const Layer>;

    struct LayerSnap;
    using LayerSnapPtr  = Ref<LayerSnap>;
    using LayerSnapCPtr = Ref<const LayerSnap>;
    
    struct LayerData;
    using LayerDataPtr  = Ref<LayerData>;
    using LayerDataCPtr = Ref<const LayerData>;

    template <class> class ID;
    using LayerID = ID<Layer>;
    
    class LayerMeta;
}
