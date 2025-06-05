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
    class Group;
    using GroupPtr      = Ref<Group>;
    using GroupCPtr     = Ref<const Group>;

    struct GroupSnap;
    using GroupSnapPtr  = Ref<GroupSnap>;
    using GroupSnapCPtr = Ref<const GroupSnap>;
    
    struct GroupData;
    using GroupDataPtr  = Ref<GroupData>;
    using GroupDataCPtr = Ref<const GroupData>;

    template <class> class ID;
    using GroupID = ID<Group>;
    
    class GroupInfo;
}
