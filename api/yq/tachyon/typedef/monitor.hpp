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
    class Monitor;
    using MonitorPtr      = Ref<Monitor>;
    using MonitorCPtr     = Ref<const Monitor>;

    struct MonitorSnap;
    using MonitorSnapPtr  = Ref<MonitorSnap>;
    using MonitorSnapCPtr = Ref<const MonitorSnap>;
    
    struct MonitorData;
    using MonitorDataPtr  = Ref<MonitorData>;
    using MonitorDataCPtr = Ref<const MonitorData>;

    template <class> class ID;
    using MonitorID = ID<Monitor>;
    
    class MonitorMeta;
}
