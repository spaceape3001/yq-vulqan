////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Manager.hpp"
#include "ManagerInfoWriter.hpp"

namespace yq::tachyon {
    ManagerInfo::ManagerInfo(std::string_view zName, post::PBXInfo& base, const std::source_location& sl) :
        post::PBXInfo(zName, base, sl)
    {
        set(Flag::MANAGER);
    }

    void Manager::init_info()
    {
        auto w = writer<Manager>();
        w.description("Manager abstract base class");
    }

    Manager::Manager(const Param& p) : post::PBX(p)
    {
    }
    
    Manager::~Manager()
    {
    }
    
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Manager)
