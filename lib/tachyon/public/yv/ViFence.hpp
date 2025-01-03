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
    class ViVisualizer;
    
    class ViFence {
    public:
    
        ViFence();
        ViFence(ViVisualizer&);
        ~ViFence();

        operator VkFence () const { return m_fence; }
    
        bool            consistent() const;
        VkFence         fence() const { return m_fence; }
        std::error_code status() const;
        bool            valid() const;
        ViVisualizer*   visualizer() const { return m_viz; }

        std::error_code init(ViVisualizer&);
        void            kill();
        std::error_code reset();
        std::error_code wait(uint64_t timeout=DEFAULT_WAIT_TIMEOUT);

    private:
        ViVisualizer*   m_viz   = nullptr;
        VkFence         m_fence = nullptr;
        
        std::error_code _init(ViVisualizer&);
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
