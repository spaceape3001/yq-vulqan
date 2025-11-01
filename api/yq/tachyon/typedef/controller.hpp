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
    class Controller;
    using ControllerPtr     = Ref<Controller>;
    using ControllerCPtr    = Ref<const Controller>;

    struct ControllerSnap;
    using ControllerSnapPtr  = Ref<ControllerSnap>;
    using ControllerSnapCPtr = Ref<const ControllerSnap>;
    
    struct ControllerData;
    using ControllerDataPtr  = Ref<ControllerData>;
    using ControllerDataCPtr = Ref<const ControllerData>;

    template <class> class ID;
    using ControllerID = ID<Controller>;
    
    class ControllerMeta;
}
