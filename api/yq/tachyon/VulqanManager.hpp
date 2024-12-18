////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/app/Manager.hpp>
#include <yq/tachyon/vulqan.hpp>

namespace yq {
    class BasicApp;
}

namespace yq::tachyon {
    struct AppCreateInfo;

    class VulqanManager : public Manager {
        YQ_OBJECT_DECLARE(VulqanManager, Manager)
    public:
    
        static VulqanManager*   manager();
        static VkInstance       instance();
        static bool             initialized();
        
        static uint32_t         vulkan_api();
    
        VulqanManager(const AppCreateInfo&);
        ~VulqanManager();
        
        static void init_info();

    protected:
    
    private:
        struct Common;
        static Common&  common();
        
        static void  _init(const AppCreateInfo&);
        static void  _kill();
    };
}
