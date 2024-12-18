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
    class Camera;
    using CameraPtr     = Ref<Camera>;
    using CameraCPtr    = Ref<const Camera>;
}
