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
    class Gesture;
    using GesturePtr   = Ref<Gesture>;
    
    //  And figure out some generic gesture handler... lookup table for elements, for instance
}
