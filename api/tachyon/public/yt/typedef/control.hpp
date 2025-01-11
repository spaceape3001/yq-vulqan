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
    class Control;
    using ControlPtr      = Ref<Control>;
    using ControlCPtr     = Ref<const Control>;

    struct ControlSnap;
    using ControlSnapPtr  = Ref<ControlSnap>;
    using ControlSnapCPtr = Ref<const ControlSnap>;
    
    struct ControlData;
    using ControlDataPtr  = Ref<ControlData>;
    using ControlDataCPtr = Ref<const ControlData>;

    template <class> class ID;
    using ControlID = ID<Control>;
}
