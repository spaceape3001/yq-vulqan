////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <tachyon/typedef/vi_tasker.hpp>
#include <tachyon/typedef/vi_thread.hpp>
//#include <tachyon/vulkan/ViCommandPool.hpp>
#include <system_error>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {

    class ViVisualizer;
    
    struct ViTaskerOptions {
    };

    /*! \brief Task/Frame
    
        Likely the extension to task/frame?
    */
    class ViTasker : public RefCount {
    public:
    
        ViTasker();
        ViTasker(ViVisualizer&, const ViTaskerOptions& options={});
        ~ViTasker();
        
        std::error_code init(ViVisualizer&, const ViTaskerOptions& options={});
        void    kill();
        bool    consistent() const;
        bool    valid() const;
        
        ViVisualizer*       viz() const { return m_viz; }
        VkCommandPool       command_pool() const { return m_commandPool; }
        VkCommandBuffer     command_buffer() const { return m_commandBuffer; }
    
    private:
        ViVisualizer*                   m_viz               = nullptr;
        VkCommandPool                   m_commandPool       = nullptr;
        VkCommandBuffer                 m_commandBuffer     = nullptr;

        std::error_code _init(ViVisualizer&, const ViTaskerOptions& options={});
        void            _kill();
    };
}
