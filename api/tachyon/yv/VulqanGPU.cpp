////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VulqanGPU.hpp"
#include <yt/os/GraphicsCardInfoWriter.hpp>
#include "VqUtils.hpp"

namespace yq::tachyon {
    VulqanGPU::VulqanGPU(VkPhysicalDevice physDev) : m_physDevice(physDev)
    {
    }
    
    VulqanGPU::~VulqanGPU()
    {
    }
        
    Execution VulqanGPU::setup(const Context&ctx) 
    {
        if(!m_init){
            update();
            m_init  = true;
        }
        return GraphicsCard::setup(ctx);
    }

    void VulqanGPU::snap(GraphicsCardSnap&sn) const
    {
        GraphicsCard::snap(sn);
        sn.name = m_name;
        sn.heap = m_heap;
    }

    void VulqanGPU::update()
    {
        m_name  = vqName(m_physDevice);
        
        //  approximate... might have some error
        VkPhysicalDeviceMemoryProperties    memProps;
        vkGetPhysicalDeviceMemoryProperties(m_physDevice, &memProps);
        m_heap  = 0;
        for(size_t i=0;i<memProps.memoryHeapCount;++i){
            if(memProps.memoryHeaps[i].flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT)
                m_heap += memProps.memoryHeaps[i].size;
        }
    }

    void VulqanGPU::init_info()
    {
        auto w = writer<VulqanGPU>();
        w.description("Vulkan GPU");
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::VulqanGPU)
