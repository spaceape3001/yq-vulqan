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
    class Manager;
    using ManagerPtr       = Ref<Manager>;
    using ManagerCPtr      = Ref<const Manager>;

    struct ManagerSnap;
    using ManagerSnapPtr  = Ref<ManagerSnap>;
    using ManagerSnapCPtr = Ref<const ManagerSnap>;
    
    struct ManagerData;
    using ManagerDataPtr  = Ref<ManagerData>;
    using ManagerDataCPtr = Ref<const ManagerData>;

    template <class> class ID;
    
    using ManagerID = ID<Manager>;
}
