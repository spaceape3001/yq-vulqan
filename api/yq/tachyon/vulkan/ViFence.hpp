////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <system_error>
#include <vulkan/vulkan_core.h>
#include <yq/tachyon/config/vulqan.hpp>

namespace yq::tachyon {
    class ViDevice;

    class ViFence {
    public:
    
        ViFence(ViDevice&);
        ~ViFence();

        operator VkFence () const { return m_fence; }
    
        VkFence         fence() const { return m_fence; }
        std::error_code status() const;
        bool            valid() const { return static_cast<bool>(m_fence); }

        std::error_code reset();
        std::error_code wait(uint64_t timeout=DEFAULT_WAIT_TIMEOUT);

    private:
        ViDevice&       m_device;
        VkFence         m_fence     = nullptr;
        
        std::error_code _wait(uint64_t);
        std::error_code _reset();
    };
}
