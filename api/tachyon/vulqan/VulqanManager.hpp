////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/EventManager.hpp>
#include <tachyon/event/EventSocket.hpp>
#include <tachyon/vulqan/vulqan.hpp>

namespace yq::tachyon {
    class BasicApp;
    struct AppCreateInfo;

    class VulqanManager : public Manager, public EventProducer, public EventSocket {
        YQ_OBJECT_DECLARE(VulqanManager, Manager)
    public:
    
        static VulqanManager*   manager();
        static VkInstance       instance();
        
        static uint32_t         vulkan_api();
    
        VulqanManager(const AppCreateInfo&);
        ~VulqanManager();

    protected:
        void  handle(Event&) override;
        
    
    private:
        struct Common;
        static Common&  common();
        
        static void  _init(const AppCreateInfo&);
        static void  _kill();
    };
}
