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
    class Light;
    using LightPtr      = Ref<Light>;
    using LightCPtr     = Ref<const Light>;

    struct LightSnap;
    using LightSnapPtr  = Ref<LightSnap>;
    using LightSnapCPtr = Ref<const LightSnap>;
    
    struct LightData;
    using LightDataPtr  = Ref<LightData>;
    using LightDataCPtr = Ref<const LightData>;

    template <class> class ID;
    using LightID = ID<Light>;
}
