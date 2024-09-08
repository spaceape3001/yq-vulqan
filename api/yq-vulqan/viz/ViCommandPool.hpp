////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq::tachyon {
    class ViCommandPool {
    public:
    
        ViCommandPool();
        ~ViCommandPool();
        
        
        std::error_code init(ViVisualizer&, const VkCommandPoolCreateInfo&);
        
        std::error_code init(ViVisualizer&, const VkCommandPoolCreateInfo&);
        void            kill(ViVisualizer&);
        
    private:
        VkCommandPool       m_pool;
    };
}
