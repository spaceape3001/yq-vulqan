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
    using ManagerPtr     = Ref<Manager>;
    using ManagerCPtr    = Ref<const Manager>;

    template <class> class ID;
    using ManagerID = ID<Manager>;
}
