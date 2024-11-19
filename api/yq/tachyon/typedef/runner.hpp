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
    class Runner;
    
    template <class> class ID;
    using RunnerID = ID<Runner>;

    /*
        DO NOT DECLARE THREAD ID with the ID class... different IDs.
    */
    
    struct RunnerData;
    using RunnerDataPtr     = Ref<RunnerData>;
    using RunnerDataCPtr    = Ref<const RunnerData>;
}
