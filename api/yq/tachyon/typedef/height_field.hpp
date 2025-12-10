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
    class HeightField;
    using HeightFieldPtr            = Ref<HeightField>;
    using HeightFieldCPtr           = Ref<const HeightField>;
    
    struct HeightFieldInfo;

    template <class> class ID;
    
    using HeightFieldID     = ID<HeightField>;
}
