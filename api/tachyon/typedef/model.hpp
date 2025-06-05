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
    class Model;
    using ModelPtr      = Ref<Model>;
    using ModelCPtr     = Ref<const Model>;

    struct ModelSnap;
    using ModelSnapPtr  = Ref<ModelSnap>;
    using ModelSnapCPtr = Ref<const ModelSnap>;
    
    struct ModelData;
    using ModelDataPtr  = Ref<ModelData>;
    using ModelDataCPtr = Ref<const ModelData>;

    template <class> class ID;
    using ModelID = ID<Model>;
    
    class ModelInfo;
}
