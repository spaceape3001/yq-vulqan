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
    class ViDescriptorPool;
    using ViDescriptorPoolPtr            = Ref<ViDescriptorPool>;
    using ViDescriptorPoolCPtr           = Ref<const ViDescriptorPool>;
}
