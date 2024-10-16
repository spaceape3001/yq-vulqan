////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Manager.hpp"
#include "ManagerInfoWriter.hpp"

namespace yq::tachyon {
    ManagerInfo::ManagerInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::MANAGER);
    }

    void Manager::init_info()
    {
        auto w = writer<Manager>();
        w.description("Manager abstract base class");
    }

    Manager::Manager()
    {
    }
    
    Manager::~Manager()
    {
    }
    
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Manager)
