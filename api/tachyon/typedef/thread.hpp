////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vector>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Thread;
    using ThreadPtr         = Ref<Thread>;
    using ThreadCPtr        = Ref<const Thread>;
    
    using ThreadPtrVector   = std::vector<ThreadPtr>;
    
    template <class> class ID;
    using ThreadID = ID<Thread>;
    
    struct ThreadSnap;
    using ThreadSnapPtr     = Ref<ThreadSnap>;
    using ThreadSnapCPtr    = Ref<const ThreadSnap>;
    
    struct ThreadData;
    using ThreadDataPtr     = Ref<ThreadData>;
    using ThreadDataCPtr    = Ref<const ThreadData>;
    
    class ThreadInfo;
}
