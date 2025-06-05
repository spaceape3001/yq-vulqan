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
    class Keyboard;
    using KeyboardPtr      = Ref<Keyboard>;
    using KeyboardCPtr     = Ref<const Keyboard>;

    struct KeyboardSnap;
    using KeyboardSnapPtr  = Ref<KeyboardSnap>;
    using KeyboardSnapCPtr = Ref<const KeyboardSnap>;
    
    struct KeyboardData;
    using KeyboardDataPtr  = Ref<KeyboardData>;
    using KeyboardDataCPtr = Ref<const KeyboardData>;

    template <class> class ID;
    using KeyboardID = ID<Keyboard>;
    
    class KeyboardInfo;
}
