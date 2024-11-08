////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/PBX.hpp>
#include <yq/tachyon/core/Tachyon.hpp>

namespace yq::tachyon {

    class ManagerInfo : public TachyonInfo {
    public:
        template <typename C> class Writer;

        ManagerInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Manager of something in the application
    */
    class Manager : public Tachyon {
        YQ_OBJECT_INFO(ManagerInfo)
        YQ_OBJECT_DECLARE(Manager, Tachyon)
    public:
    
        static void init_info();

        using Tachyon::Param;

        Manager(const Param& p = {});
        ~Manager();
    };
}
