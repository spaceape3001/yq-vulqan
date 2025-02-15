////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <filesystem>
#include <vector>
#include <yq/core/Any.hpp>

namespace yq::tachyon {

    class PropertyInfo;
    class DelegateInfo;
    class TachyonInfo;

    struct Save {
        struct property_t {
            const PropertyInfo*     info    = nullptr;
            Any                     value;
        };
        
        struct object_t {
            std::vector<property_t> properties;
        };
        
        struct delegate_t : public object_t {
            const DelegateInfo*     info    = nullptr;
        };
        
        struct tachyon_t : public object_t {
            const TachyonInfo*      info    = nullptr;
            uint64_t                id      = 0ULL;
            std::vector<tachyon_t>  children;
            std::vector<delegate_t> delegates;
        };
        
        struct thread_t : public tachyon_t {
            std::vector<tachyon_t>  tachyons;
        };
        
        static constexpr const char* szExtension    = "tsx";
        
        //! Loads the xml (assumes it's already clear)
        std::error_code  load_xml(const std::filesystem::path&);
        std::error_code  save_xml(const std::filesystem::path&) const;
    };
}

