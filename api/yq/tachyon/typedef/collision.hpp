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
    class Collision;
    using CollisionPtr      = Ref<Collision>;
    using CollisionCPtr     = Ref<const Collision>;

    struct CollisionSnap;
    using CollisionSnapPtr  = Ref<CollisionSnap>;
    using CollisionSnapCPtr = Ref<const CollisionSnap>;
    
    struct CollisionData;
    using CollisionDataPtr  = Ref<CollisionData>;
    using CollisionDataCPtr = Ref<const CollisionData>;

    template <class> class ID;
    using CollisionID = ID<Collision>;
    
    class CollisionMeta;
}
