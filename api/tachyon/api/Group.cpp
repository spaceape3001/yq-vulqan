////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Group.hpp>
#include <tachyon/api/GroupData.hpp>
#include <tachyon/api/GroupMetaWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Group);
YQ_TYPE_IMPLEMENT(yq::tachyon::GroupID)

namespace yq::tachyon {

    GroupMeta::GroupMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) :
        TachyonMeta(name, base, sl)
    {
        set(Type::Group);
    }
    
    GroupMeta::~GroupMeta()
    {
    }
    

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

    void Group::init_info()
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


