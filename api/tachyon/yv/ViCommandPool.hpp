////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <system_error>
#include <vulkan/vulkan_core.h>
#include <yq/core/Flags.hpp>

namespace yq::tachyon {
    class ViVisualizer;
    

    enum class VqCommandPoolCreateBit : uint8_t {
        Transient = 1,
        ResetCommandBuffer = 2,
        Protected = 3
    };

    enum class VqCommandPoolResetBit : uint8_t {
        ReleaseResources = 1
    };
    
    using VqCommandPoolCreateFlags = Flags<VqCommandPoolCreateBit>;
    using VqCommandPoolResetFlags = Flags<VqCommandPoolResetBit>;

    class ViCommandPool {
    public:
    
        ViCommandPool();
        ViCommandPool(ViVisualizer&, uint32_t queueFamilyIndex, VqCommandPoolCreateFlags={});
        ViCommandPool(ViVisualizer&, const VkCommandPoolCreateInfo&);
        ~ViCommandPool();
        
        operator VkCommandPool() const { return m_pool; }

        VkCommandPool   command_pool() const { return m_pool; }
        bool            consistent() const;
        bool            valid() const;
        ViVisualizer*   visualizer() const { return m_viz; }

        std::error_code init(ViVisualizer&, uint32_t queueFamilyIndex, VqCommandPoolCreateFlags={});
        std::error_code init(ViVisualizer&, const VkCommandPoolCreateInfo&);
        void            kill();
        std::error_code reset(VqCommandPoolResetFlags={});
        
    private:
        ViVisualizer*       m_viz  = nullptr;
        VkCommandPool       m_pool = nullptr;
        
        ViCommandPool(const ViCommandPool&) = delete;
        ViCommandPool(ViCommandPool&&) = delete;
        ViCommandPool& operator=(const ViCommandPool&) = delete;
        ViCommandPool& operator=(ViCommandPool&&) = delete;
        
        static VkCommandPoolCreateInfo _info(uint32_t queueFamilyIndex, VqCommandPoolCreateFlags);
        std::error_code _init(ViVisualizer&, const VkCommandPoolCreateInfo&);
        void            _kill();
        void            _wipe();
        std::error_code _reset(VkCommandPoolResetFlags);
    };
}
