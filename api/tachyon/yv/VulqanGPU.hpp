////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/GraphicsCard.hpp>
#include <yv/vulqan.hpp>

namespace yq::tachyon {
    class AppCreateInfo;

    class VulqanGPU : public GraphicsCard {
        YQ_TACHYON_DECLARE(VulqanGPU, GraphicsCard)
    public:
    
        // Thought is to have *THIS* become the logical device.... 
        //  (ie, the visualizer though not the surface), might have metrics
        //  And thus rename to VulqanDevice????
    
        VulqanGPU(VkPhysicalDevice);
        ~VulqanGPU();
        
        static void init_info();
        
        VkPhysicalDevice    physical_device() const { return m_physDevice; }
        
        Execution setup(const Context&) override;
        
        void snap(GraphicsCardSnap&) const;
        
    private:
    
        void    update();
    
        VkPhysicalDevice    m_physDevice    = nullptr;
        std::string         m_name;
        size_t              m_heap          = 0;
        bool                m_init          = false;
    };
}
