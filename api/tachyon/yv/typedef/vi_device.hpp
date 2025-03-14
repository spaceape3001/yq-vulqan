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
    class ViDevice;
    using ViDevicePtr           = Ref<ViDevice>;
    using ViDeviceCPtr          = Ref<const ViDevice>;
}
