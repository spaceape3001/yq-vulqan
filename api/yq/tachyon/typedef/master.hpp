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
    class Master;
    using MasterPtr       = Ref<Master>;
    using MasterCPtr      = Ref<const Master>;

    struct MasterSnap;
    using MasterSnapPtr  = Ref<MasterSnap>;
    using MasterSnapCPtr = Ref<const MasterSnap>;
    
    struct MasterData;
    using MasterDataPtr  = Ref<MasterData>;
    using MasterDataCPtr = Ref<const MasterData>;

    template <class> class ID;
    
    using MasterID = ID<Master>;
    
    class MasterMeta;
}
