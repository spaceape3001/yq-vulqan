////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <system_error>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
    class ViVisualizer;
    
    enum class ViFenceStatus {
        Ready       = 0,
        NotReady,
        DeviceLost,
        Uninitialized,
        GenericError
    };
    
    class ViFence {
    public:
    
        ViFence();
        ~ViFence();


        std::error_code init(ViVisualizer&);
        void            kill();
        
        operator VkFence () const { return m_fence; }
    
        bool            consistent() const;
        ViFenceStatus   status() const;
        bool            valid() const;

    private:
        ViVisualizer*   m_viz   = nullptr;
        VkFence         m_fence = nullptr;
    };
}
