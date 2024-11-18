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
    class Thread;
    
    template <class> class ID;
    using ThreadID = ID<Thread>;

    /*
        DO NOT DECLARE THREAD ID with the ID class... different IDs.
    */
}
