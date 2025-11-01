////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/api/ManagerData.hpp>
#include <yq/tachyon/api/ManagerMetaWriter.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    ManagerData::ManagerData() = default;
    ManagerData::~ManagerData() = default;

    /////////////////////////////////////////////////////////////////////////////

    ManagerMeta::ManagerMeta(std::string_view zName, TachyonMeta& base, const std::source_location& sl) :
        TachyonMeta(zName, base, sl)
    {
        set(Flag::MANAGER);
        set(Type::Manager);
    }

    /////////////////////////////////////////////////////////////////////////////

    ManagerSnap::ManagerSnap() = default;
    ManagerSnap::~ManagerSnap() = default;

    /////////////////////////////////////////////////////////////////////////////

    Manager::Manager(const Param& p) : Tachyon(p)
    {
    }
    
    Manager::~Manager()
    {
    }
    
    void Manager::init_meta()
    {
        auto w = writer<Manager>();
        w.description("Manager abstract base class, tries to be bossy");

        auto wt = writer<ManagerID>();
        wt.description("Manager Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Manager>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Manager)
YQ_TYPE_IMPLEMENT(yq::tachyon::ManagerID)
