////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <system_error>
#include <vulkan/vulkan_core.h>
#include <yt/config/vulqan.hpp>

namespace yq::tachyon {
    class ViFence {
    public:
    
        ViFence();
        ViFence(VkDevice);
        ~ViFence();

        operator VkFence () const { return m_fence; }
    
        bool            consistent() const;
        VkFence         fence() const { return m_fence; }
        std::error_code status() const;
        bool            valid() const;
        //ViVisualizer*   visualizer() const { return m_viz; }

        std::error_code init(VkDevice);
        void            kill();
        std::error_code reset();
        std::error_code wait(uint64_t timeout=DEFAULT_WAIT_TIMEOUT);

    private:
        VkDevice        m_device    = nullptr;
        VkFence         m_fence     = nullptr;
        
        std::error_code _init(VkDevice);
        void            _kill();
        std::error_code _wait(uint64_t);
        void            _wipe();
        std::error_code _reset();
        
        ViFence(const ViFence&) = delete;
        ViFence(ViFence&&) = delete;
        ViFence& operator=(const ViFence&) = delete;
        ViFence& operator=(ViFence&&) = delete;
    };
}
