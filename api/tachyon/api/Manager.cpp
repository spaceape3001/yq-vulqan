////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Manager.hpp>
#include <tachyon/api/ManagerData.hpp>
#include <tachyon/api/ManagerInfoWriter.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    ManagerData::ManagerData() = default;
    ManagerData::~ManagerData() = default;

    /////////////////////////////////////////////////////////////////////////////

    ManagerInfo::ManagerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
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
    
    void Manager::init_info()
    {
        auto w = writer<Manager>();
        w.description("Manager abstract base class, tries to be bossy");

        auto wt = writer<ManagerID>();
        wt.description("Manager Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Manager)
YQ_TYPE_IMPLEMENT(yq::tachyon::ManagerID)
