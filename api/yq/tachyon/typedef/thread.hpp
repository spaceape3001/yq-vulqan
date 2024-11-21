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
    
    struct ThreadSnap;
    using ThreadSnapPtr     = Ref<ThreadSnap>;
    using ThreadSnapCPtr    = Ref<const ThreadSnap>;
    
    struct ThreadData;
    using ThreadDataPtr     = Ref<ThreadData>;
    using ThreadDataCPtr    = Ref<const ThreadData>;
}
