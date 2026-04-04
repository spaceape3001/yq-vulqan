////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MGroup.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Group.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MGroup)

namespace yq::tachyon {
    MGroup::MGroup(TypedID tid) : MTachyon(tid)
    {
    }
    
    MGroup::~MGroup()
    {
    }
    
    void MGroup::init_meta()
    {
        auto w = writer<MGroup>();
        w.description("Group Qt Binder");
        w.manage<Group>();
    }
}


#include "moc_MGroup.cpp"
