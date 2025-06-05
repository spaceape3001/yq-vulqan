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
    class Mouse;
    using MousePtr      = Ref<Mouse>;
    using MouseCPtr     = Ref<const Mouse>;

    struct MouseSnap;
    using MouseSnapPtr  = Ref<MouseSnap>;
    using MouseSnapCPtr = Ref<const MouseSnap>;
    
    struct MouseData;
    using MouseDataPtr  = Ref<MouseData>;
    using MouseDataCPtr = Ref<const MouseData>;

    template <class> class ID;
    using MouseID = ID<Mouse>;
    
    class MouseInfo;
}
