////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/vulkan/vulqan.hpp>

namespace yq {
    class BasicApp;
}

namespace yq::tachyon {
    struct AppCreateInfo;
    class VulqanGPU;

    class VulqanManager : public Manager {
        YQ_TACHYON_DECLARE(VulqanManager, Manager)
    public:
    
        static VulqanManager*   manager();
        static VkInstance       instance();
        static bool             initialized();
        
        static uint32_t         vulkan_api();
        
        static std::span<const char*>   extensions();
    
        VulqanManager();
        virtual ~VulqanManager();
        
        static void init_meta();

    protected:
    
        Execution setup(const Context&) override;
        Execution teardown(const Context&) override;
    
    
    private:
    
        struct Common;
        static Common&  common();
        
        void  _init();
        void  _kill();
        
        static VkBool32 debugging_callback(
            VkDebugUtilsMessageSeverityFlagBitsEXT           messageSeverity,
            VkDebugUtilsMessageTypeFlagsEXT                  messageTypes,
            const VkDebugUtilsMessengerCallbackDataEXT*      pCallbackData,
            VulqanManager*                                   pManager);
        
        enum class X {
            Init,
            Killed
        };
        Flags<X>                    m_flags;
        std::vector<Ref<VulqanGPU>> m_devices;
    };
}
