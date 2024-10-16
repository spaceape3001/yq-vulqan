////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Object.hpp>

namespace yq::tachyon {

    class ManagerInfo : public ObjectInfo {
    public:
        template <typename C> class Writer;

        ManagerInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Manager of something in the application
    */
    class Manager : public Object {
        YQ_OBJECT_INFO(ManagerInfo)
        YQ_OBJECT_DECLARE(Manager, Object)
    public:
    
        static void init_info();

        Manager();
        ~Manager();
    };
}
