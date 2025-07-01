////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Tachyon.hpp>
#include <tachyon/typedef/manager.hpp>

namespace yq::tachyon {

    class ManagerMeta : public TachyonMeta {
    public:
        template <typename C> class Writer;

        ManagerMeta(std::string_view zName, TachyonMeta& base, const std::source_location& sl=std::source_location::current());
    };

    /*! \brief Manager of something in the application
    */
    class Manager : public Tachyon {
        YQ_TACHYON_META(ManagerMeta)
        YQ_TACHYON_DATA(ManagerData)
        YQ_TACHYON_SNAP(ManagerSnap)
        YQ_TACHYON_DECLARE(Manager, Tachyon)
    public:
    
        static void init_meta();

        using Tachyon::Param;

        Manager(const Param& p = {});
        virtual ~Manager();
        
        ManagerID id() const { return { UniqueID::id()}; }
    };
}

YQ_TYPE_DECLARE(yq::tachyon::ManagerID)
