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
    class Entity³;
    using Entity³Ptr         = Ref<Entity³>;
    using Entity³CPtr        = Ref<const Entity³>;

    struct Entity³Snap;
    using Entity³SnapPtr     = Ref<Entity³Snap>;
    using Entity³SnapCPtr    = Ref<const Entity³Snap>;
    
    struct Entity³Data;
    using Entity³DataPtr     = Ref<Entity³Data>;
    using Entity³DataCPtr    = Ref<const Entity³Data>;

    template <class> class ID;
    using Entity³ID = ID<Entity³>;
    
    class Entity³Meta;
}
