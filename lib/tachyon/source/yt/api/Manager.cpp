////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/api/Manager.hpp>
#include <yt/api/ManagerBind.hpp>
#include <yt/api/ManagerData.hpp>
#include <yt/api/ManagerInfoWriter.hpp>

namespace yq::tachyon {
    ManagerBind::ManagerBind(const Manager* v) : m_manager(v ? v->id() : ManagerID{})
    {
    }

    ManagerInfo::ManagerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
        set(Flag::MANAGER);
        set(Type::Manager);
    }

    void Manager::init_info()
    {
        auto w = writer<Manager>();
        w.description("Manager abstract base class");
    }

    Manager::Manager(const Param& p) : Tachyon(p)
    {
    }
    
    Manager::~Manager()
    {
    }
    
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Manager)
