////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/PBX.hpp>

namespace yq::tachyon {

    class ManagerInfo : public post::PBXInfo {
    public:
        template <typename C> class Writer;

        ManagerInfo(std::string_view zName, post::PBXInfo& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Manager of something in the application
    */
    class Manager : public post::PBX {
        YQ_OBJECT_INFO(ManagerInfo)
        YQ_OBJECT_DECLARE(Manager, post::PBX)
    public:
    
        static void init_info();

        using post::PBX::Param;

        Manager(const Param& p = {});
        ~Manager();
    };
}
