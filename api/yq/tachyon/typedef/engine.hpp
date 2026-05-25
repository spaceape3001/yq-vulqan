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
    class Engine;
    using EnginePtr       = Ref<Engine>;
    using EngineCPtr      = Ref<const Engine>;

    struct EngineSnap;
    using EngineSnapPtr  = Ref<EngineSnap>;
    using EngineSnapCPtr = Ref<const EngineSnap>;
    
    struct EngineData;
    using EngineDataPtr  = Ref<EngineData>;
    using EngineDataCPtr = Ref<const EngineData>;

    template <class> class ID;
    
    using EngineID = ID<Engine>;
    
    class EngineMeta;
}
