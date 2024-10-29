////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Manager.hpp>
#include <tachyon/vulqan/vulqan.hpp>

namespace yq::tachyon {
    class BasicApp;
    struct AppCreateInfo;

    class VulqanManager : public Manager {
        YQ_OBJECT_DECLARE(VulqanManager, Manager)
    public:
    
        static VulqanManager*   manager();
        static VkInstance       instance();
        
        static uint32_t         vulkan_api();
    
        VulqanManager(const AppCreateInfo&);
        ~VulqanManager();

    protected:
    
    private:
        struct Common;
        static Common&  common();
        
        static void  _init(const AppCreateInfo&);
        static void  _kill();
    };
}
