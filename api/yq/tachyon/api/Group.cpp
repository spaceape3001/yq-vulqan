////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Group.hpp>
#include <yq/tachyon/api/GroupData.hpp>
#include <yq/tachyon/api/GroupMetaWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Group);
YQ_TYPE_IMPLEMENT(yq::tachyon::GroupID)

namespace yq::tachyon {

    GroupData::GroupData() = default;
    GroupData::~GroupData() = default;
    void GroupData::init_meta()
    {
        auto w = writer<GroupData>();
        w.description("Group Frame Data");
    }

    //////////////////////////////

    GroupMeta::GroupMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) :
        TachyonMeta(name, base, sl)
    {
        set(Type::Group);
    }
    
    GroupMeta::~GroupMeta()
    {
    }
    
    //////////////////////////////

    GroupSnap::GroupSnap() = default;
    GroupSnap::~GroupSnap() = default;
    void GroupSnap::init_meta()
    {
        auto w = writer<GroupSnap>();
        w.description("Group Snapshot");
        w.property("order", READ_ONLY, &GroupSnap::order);
    }

    //////////////////////////////

    Group::Group(const Param&p) : Tachyon(p)
    {
    }
    
    Group::~Group()
    {
    }

    void Group::snap(GroupSnap&sn) const
    {
        Tachyon::snap(sn);
        sn.order    = m_order;
    }

    void Group::finalize(GroupData&data) const
    {
        Tachyon::finalize(data);
    }

    void Group::init_meta()
    {
        auto w = writer<Group>();
        w.description("Group");

        auto wt = writer<GroupID>();
        wt.description("Group Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Group>);
        wt.casts<TachyonID>();
    }

}


