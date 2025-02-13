////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Manager.hpp>
#include <yv/vulqan.hpp>

namespace yq {
    class BasicApp;
}

namespace yq::tachyon {
    struct AppCreateInfo;

    class VulqanManager : public Manager {
        YQ_TACHYON_DECLARE(VulqanManager, Manager)
    public:
    
        static VulqanManager*   manager();
        static VkInstance       instance();
        static bool             initialized();
        
        static uint32_t         vulkan_api();
    
        VulqanManager();
        ~VulqanManager();
        
        static void init_info();

    protected:
    
        Execution setup(const Context&) override;
    
    
    private:
    
        struct Common;
        static Common&  common();
        
        static void  _init();
        static void  _kill();
        
        bool                    m_init  = false;
    };
}
