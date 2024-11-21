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
    using LightPtr     = Ref<Light>;
    using LightCPtr    = Ref<const Light>;

    template <class> class ID;
    using LightID = ID<Light>;
}
