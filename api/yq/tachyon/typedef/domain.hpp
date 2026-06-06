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
    class Domain;
    using DomainPtr         = Ref<Domain>;
    using DomainCPtr        = Ref<const Domain>;

    struct DomainSnap;
    using DomainSnapPtr     = Ref<DomainSnap>;
    using DomainSnapCPtr    = Ref<const DomainSnap>;
    
    struct DomainData;
    using DomainDataPtr     = Ref<DomainData>;
    using DomainDataCPtr    = Ref<const DomainData>;

    template <class> class ID;
    using DomainID = ID<Domain>;
    
    class DomainTweak;
    using DomainTweakCPtr   = Ref<DomainTweak>;
    
    class DomainMeta;
}
