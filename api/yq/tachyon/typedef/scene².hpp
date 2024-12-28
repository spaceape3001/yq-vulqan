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
    class Scene²;
    using Scene²Ptr      = Ref<Scene²>;
    using Scene²CPtr     = Ref<const Scene²>;

    struct Scene²Snap;
    using Scene²SnapPtr  = Ref<Scene²Snap>;
    using Scene²SnapCPtr = Ref<const Scene²Snap>;
    
    struct Scene²Data;
    using Scene²DataPtr  = Ref<Scene²Data>;
    using Scene²DataCPtr = Ref<const Scene²Data>;

    template <class> class ID;
    using Scene²ID = ID<Scene²>;
}
