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
    class Entity;
    using EntityPtr      = Ref<Entity>;
    using EntityCPtr     = Ref<const Entity>;

    struct EntitySnap;
    using EntitySnapPtr  = Ref<EntitySnap>;
    using EntitySnapCPtr = Ref<const EntitySnap>;
    
    struct EntityData;
    using EntityDataPtr  = Ref<EntityData>;
    using EntityDataCPtr = Ref<const EntityData>;

    template <class> class ID;
    using EntityID = ID<Entity>;
    
    class EntityMeta;
}
