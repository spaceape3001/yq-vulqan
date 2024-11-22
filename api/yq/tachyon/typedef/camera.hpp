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
    using CameraPtr      = Ref<Camera>;
    using CameraCPtr     = Ref<const Camera>;

    struct CameraSnap;
    using CameraSnapPtr  = Ref<CameraSnap>;
    using CameraSnapCPtr = Ref<const CameraSnap>;
    
    struct CameraData;
    using CameraDataPtr  = Ref<CameraData>;
    using CameraDataCPtr = Ref<const CameraData>;

    template <class> class ID;
    using CameraID = ID<Camera>;
}
