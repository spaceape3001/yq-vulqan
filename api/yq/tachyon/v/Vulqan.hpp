////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/vulqan.hpp>

namespace yq {
    class BasicApp;
}

namespace yq::tachyon {
    struct AppCreateInfo;

    class Vulqan : public Manager {
        YQ_TACHYON_DECLARE(Vulqan, Manager)
    public:
    
        static Vulqan*          manager();
        static VkInstance       instance();
        static bool             initialized();
        
        static uint32_t         vulkan_api();
    
        Vulqan(const AppCreateInfo&);
        ~Vulqan();
        
        static void init_info();

    protected:
    
    
    private:
    
        static Vulqan*          s_manager;
        static VkInstance       s_instance;
    
        struct Common;
        static Common&  common();
        
        static void  _init(const AppCreateInfo&);
        static void  _kill();
    };
}
